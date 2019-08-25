#include "svgsimpleshapetranslation.h"

#include <QXmlStreamWriter>

#include "sbsimpleshape.h"

SVGSimpleShapeTranslation::SVGSimpleShapeTranslation()
{

}

void SVGSimpleShapeTranslation::exportFillAndStroke(SBSimpleShape *simpleShape)
{
    SBSimpleShape::FillType fillType = simpleShape->fillType();
    switch (fillType)
    {
    case SBSimpleShape::FillType::NoneFillType:
        m_pWriter->writeAttribute("fill", "none");
        break;
    case SBSimpleShape::FillType::SolidFillType:
        m_pWriter->writeAttribute("fill", simpleShape->brushColor().name());
        break;
    default:
        break;
    }
    m_pWriter->writeAttribute("stroke", simpleShape->penColor().name());
    m_pWriter->writeAttribute("stroke-width", QString::number(simpleShape->strokeWidth()));
    m_pWriter->writeAttribute("stroke-opacity", QString::number(simpleShape->penColor().alpha() / 255.0));
}

