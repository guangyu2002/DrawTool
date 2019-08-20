#include "svgrecttranlation.h"

#include <QXmlStreamWriter>

#include "sbrect.h"

SVGRectTranlation::SVGRectTranlation()
{

}

void SVGRectTranlation::exportShape(SBShape *shape)
{
    SVGSimpleShapeTranslation::exportShape(shape);
    SBRect *rect = dynamic_cast<SBRect*>(shape);
    m_pWriter->writeStartElement("rect");
    m_pWriter->writeAttribute("x", QString::number(rect->begin().x()));
    m_pWriter->writeAttribute("y", QString::number(rect->begin().y()));
    m_pWriter->writeAttribute("width", QString::number(rect->width()));
    m_pWriter->writeAttribute("height", QString::number(rect->height()));
    m_pWriter->writeAttribute("fill","#000000");
    exportShapeAfter(shape);
}

void SVGRectTranlation::exportShapeAfter(SBShape *shape)
{
    m_pWriter->writeEndElement();
    SVGSimpleShapeTranslation::exportShapeAfter(shape);
}

void SVGRectTranlation::exportShapeBefore(SBShape *shape)
{
    SVGSimpleShapeTranslation::exportShapeBefore(shape);
}
