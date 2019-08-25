#include "svglinetranlation.h"

#include <QXmlStreamWriter>

#include "sbline.h"

SVGLineTranlation::SVGLineTranlation()
{

}

void SVGLineTranlation::exportShape(SBShape *shape)
{
    m_pWriter->writeStartElement("g");
    m_pWriter->writeAttribute("id", QString::number(shape->id()));
    SBLine *line = dynamic_cast<SBLine*>(shape);
    exportLine(line);
    m_pWriter->writeEndElement();
}

void SVGLineTranlation::exportLine(SBLine *line)
{
    m_pWriter->writeStartElement("line");
    m_pWriter->writeAttribute("x1", QString::number(line->begin().x()));
    m_pWriter->writeAttribute("y1", QString::number(line->begin().y()));
    m_pWriter->writeAttribute("x2", QString::number(line->end().x()));
    m_pWriter->writeAttribute("y2", QString::number(line->end().y()));
    exportFillAndStroke(line);
    m_pWriter->writeEndElement();
}

