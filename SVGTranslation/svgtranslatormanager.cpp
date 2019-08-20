#include "svgtranslatormanager.h"
#include "svgtranlationbase.h"

#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "sbdocument.h"
#include "sbshape.h"

SVGTranslatorManager::SVGTranslatorManager() :
    m_pWriter()
{
    LoadSvgTranslation();
}

void SVGTranslatorManager::LoadSvgTranslation()
{
    Metadata* metadata = ClassFactory::getInstance().GetMetadata("SVGTranlationBase");
    if (metadata != nullptr)
    {
        QHash<QString, ReflexObjectClass*>* reflexObjectClassHash = metadata->GetReflexObjects();
        QHash<QString, ReflexObjectClass*>::iterator it = reflexObjectClassHash->begin();
        while (it != reflexObjectClassHash->end())
        {
            SVGTranlationBase* tranlationBase = static_cast<SVGTranlationBase*>(metadata->CreateReflex(it.key()));
            if (tranlationBase != nullptr)
            {
                m_dsvgTranslationBases.push_back(tranlationBase);
            }
            it++;
        }
    }
}

SVGTranlationBase *SVGTranslatorManager::findSVGTranslation(const QString &typeName) const
{
    QList<SVGTranlationBase*>::const_iterator it = m_dsvgTranslationBases.begin();
    QList<SVGTranlationBase*>::const_iterator itEnd = m_dsvgTranslationBases.end();
    while (it != itEnd)
    {
        if ((*it)->typeName() == typeName)
        {
            return *it;
        }
        it++;
    }
    return nullptr;
}

SVGTranslatorManager::~SVGTranslatorManager()
{
    if (m_pWriter != nullptr)
    {
        delete m_pWriter;
    }
    m_pWriter = nullptr;
}

SVGTranslatorManager &SVGTranslatorManager::getInstance()
{
    static SVGTranslatorManager instance;
    return instance;
}

void SVGTranslatorManager::exportDefsNode()
{
    m_pWriter->writeStartElement("defs");

    m_pWriter->writeEndElement();
}

void SVGTranslatorManager::exportGRootNode(SBDocument *doc)
{
    m_pWriter->writeStartElement("g");
    exportHeadClassNode(doc);
    exportGNode("OtherClass", doc);
    m_pWriter->writeEndElement();
}

void SVGTranslatorManager::exportGNode(const QString &id, SBDocument *doc)
{
    m_pWriter->writeStartElement("g");
    m_pWriter->writeAttribute("id", id);
    QList<SBShape*> shapeList = doc->shapeList();
    int count = shapeList.count();
    for (int i = 0; i < count; ++i)
    {
        SVGTranlationBase *translationBase = findSVGTranslation(shapeList[i]->typeName());
        if (translationBase != nullptr)
        {
            translationBase->setPWriter(m_pWriter);
            translationBase->exportShape(shapeList[i]);
        }
    }
    m_pWriter->writeEndElement();
}

void SVGTranslatorManager::exportHeadClassNode(SBDocument *doc)
{
    m_pWriter->writeStartElement("g");
    m_pWriter->writeAttribute("id", "HeadClass");
    m_pWriter->writeStartElement("rect");
    m_pWriter->writeAttribute("x","111");
    m_pWriter->writeAttribute("y","111");
    m_pWriter->writeAttribute("width","111");
    m_pWriter->writeAttribute("height","111");
    m_pWriter->writeAttribute("fill","#000000");
    m_pWriter->writeEndElement();
    m_pWriter->writeEndElement();
}

QString SVGTranslatorManager::exportSvg(QByteArray &buff, SBDocument *doc)
{
    if (m_pWriter != nullptr)
    {
        delete m_pWriter;
    }
    m_pWriter = new QXmlStreamWriter(&buff);
    m_pWriter->setAutoFormatting(true);
    m_pWriter->writeStartDocument();
    m_pWriter->writeStartElement("svg");
    exportDefsNode();
    exportGRootNode(doc);
    m_pWriter->writeEndElement();
    m_pWriter->writeEndDocument();
    return "";
}
