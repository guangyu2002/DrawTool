#include "svglinetranlation.h"

SVGLineTranlation::SVGLineTranlation()
{

}

void SVGLineTranlation::exportShape(SBShape *shape)
{
    SVGSimpleShapeTranslation::exportShape(shape);
}

void SVGLineTranlation::exportShapeAfter(SBShape *shape)
{
    SVGSimpleShapeTranslation::exportShapeAfter(shape);
}

void SVGLineTranlation::exportShapeBefore(SBShape *shape)
{
    SVGSimpleShapeTranslation::exportShapeBefore(shape);
}
