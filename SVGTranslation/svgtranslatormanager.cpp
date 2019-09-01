#include "svgtranslatormanager.h"
#include "svgtranlationbase.h"

#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "sbdocument.h"
#include "sbshape.h"
#include "sbshapetools.h"

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
    QRect allShapeRect = SBShapeTools::getInstance().allShapeRect(doc->shapeList());
    m_pWriter->writeStartElement("rect");
    m_pWriter->writeAttribute("x", QString::number(allShapeRect.x()));
    m_pWriter->writeAttribute("y", QString::number(allShapeRect.y()));
    m_pWriter->writeAttribute("width", QString::number(allShapeRect.width()));
    m_pWriter->writeAttribute("height", QString::number(allShapeRect.height()));
    m_pWriter->writeAttribute("fill", doc->backColor().name());
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
    m_pWriter->writeDTD("<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"[]>");
    m_pWriter->writeStartElement("svg");
    m_pWriter->writeAttribute("xmlns", "http://www.w3.org/2000/svg");
    m_pWriter->writeAttribute("xmlns:xlink", "http://www.w3.org/1999/xlink");
    m_pWriter->writeAttribute("xmlns:cge", "http://iec.ch/TC57/2005/SVG-schema#");
    m_pWriter->writeAttribute("width", QString::number(doc->rect().width()));
    m_pWriter->writeAttribute("height", QString::number(doc->rect().height()));
    QRect allShapeRect = SBShapeTools::getInstance().allShapeRect(doc->shapeList());
    m_pWriter->writeAttribute("viewBox",QString("%1 %2 %3 %4").arg(allShapeRect.x()).arg(allShapeRect.y()).arg(allShapeRect.width()).arg(allShapeRect.height()));
    exportDefsNode();
    exportGRootNode(doc);
    m_pWriter->writeEndElement();
    m_pWriter->writeEndDocument();
    return "";
}
