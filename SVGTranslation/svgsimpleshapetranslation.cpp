#include "svgsimpleshapetranslation.h"

SVGSimpleShapeTranslation::SVGSimpleShapeTranslation()
{

}

void SVGSimpleShapeTranslation::exportShape(SBShape *shape)
{
    SVGTranlationBase::exportShape(shape);
}

void SVGSimpleShapeTranslation::exportShapeAfter(SBShape *shape)
{
    SVGTranlationBase::exportShapeAfter(shape);
}

void SVGSimpleShapeTranslation::exportShapeBefore(SBShape *shape)
{
    SVGTranlationBase::exportShapeBefore(shape);
}
