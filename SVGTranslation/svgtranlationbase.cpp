#include "svgtranlationbase.h"

#include <QXmlStreamWriter>

#include "sbshape.h"

SVGTranlationBase::SVGTranlationBase()
{

}

void SVGTranlationBase::exportShape(SBShape *shape)
{
    m_pWriter->writeStartElement("g");
    m_pWriter->writeAttribute("id", QString::number(shape->id()));
}

void SVGTranlationBase::exportShapeAfter(SBShape *shape)
{
    m_pWriter->writeEndElement();
}

void SVGTranlationBase::exportShapeBefore(SBShape *shape)
{

}


QString SVGTranlationBase::typeName() const
{
    return "shape";
}
