/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：svg模块转换管理类
 * 修改记录：
***********************************************/

#ifndef SVGTRANSLATORMANAGER_H
#define SVGTRANSLATORMANAGER_H

#include <QString>
#include <QList>

class SBShape;
class SBDocument;
class QByteArray;
class QXmlStreamWriter;
class SVGTranlationBase;
class SVGTranslatorManager
{
public:
    ~SVGTranslatorManager();
    static SVGTranslatorManager &getInstance();
    QString exportSvg(QByteArray &buff, SBDocument *doc);
private:
    SVGTranslatorManager();
    SVGTranslatorManager(const SVGTranslatorManager&) = delete;
    SVGTranslatorManager& operator=(const SVGTranslatorManager&) = delete;

    void LoadSvgTranslation();
    SVGTranlationBase *findSVGTranslation(const QString& typeName) const;
    void exportDefsNode();
    void exportGRootNode(SBDocument *doc);
    void exportGNode(const QString &id, SBDocument *doc);
    void exportHeadClassNode(SBDocument *doc);

private:
    QXmlStreamWriter *m_pWriter;
    QList<SVGTranlationBase*> m_dsvgTranslationBases;

};

#endif // SVGTRANSLATORMANAGER_H
