#include "svgrecttranlation.h"

#include <QXmlStreamWriter>

#include "sbrect.h"

SVGRectTranlation::SVGRectTranlation()
{

}

void SVGRectTranlation::exportShape(SBShape *shape)
{
    m_pWriter->writeStartElement("g");
    m_pWriter->writeAttribute("id", QString::number(shape->id()));
    SBRect *rect = dynamic_cast<SBRect*>(shape);
    exportRect(rect);
    m_pWriter->writeEndElement();
}

void SVGRectTranlation::exportRect(SBRect *rect)
{
    m_pWriter->writeStartElement("rect");
    m_pWriter->writeAttribute("x", QString::number(rect->begin().x()));
    m_pWriter->writeAttribute("y", QString::number(rect->begin().y()));
    m_pWriter->writeAttribute("width", QString::number(rect->width()));
    m_pWriter->writeAttribute("height", QString::number(rect->height()));
    exportFillAndStroke(dynamic_cast<SBSimpleShape*>(rect));
    m_pWriter->writeEndElement();
}

