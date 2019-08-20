#ifndef SVGLINETRANLATION_H
#define SVGLINETRANLATION_H

#include "svgsimpleshapetranslation.h"

class SVGLineTranlation : public SVGSimpleShapeTranslation
{
public:
    SVGLineTranlation();

    // SVGTranlationBase interface
public:
    void exportShape(SBShape *shape) Q_DECL_OVERRIDE;
    inline QString typeName() const Q_DECL_OVERRIDE { return "line"; }
protected:
    void exportShapeAfter(SBShape *shape) Q_DECL_OVERRIDE;
    void exportShapeBefore(SBShape *shape) Q_DECL_OVERRIDE;
};
REGISTERCLASS(SVGLineTranlation, SVGSimpleShapeTranslation, SVGTranlationBase)
#endif // SVGLINETRANLATION_H
