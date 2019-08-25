#ifndef SVGRECTTRANLATION_H
#define SVGRECTTRANLATION_H

#include "svgsimpleshapetranslation.h"

class SBRect;
class SVGRectTranlation : public SVGSimpleShapeTranslation
{
public:
    SVGRectTranlation();

    // SVGTranlationBase interface
public:
    inline QString typeName() const Q_DECL_OVERRIDE { return "rect"; }
    void exportShape(SBShape *shape) Q_DECL_OVERRIDE;
    void exportRect(SBRect *rect);
};
REGISTERCLASS(SVGRectTranlation, SVGSimpleShapeTranslation, SVGTranlationBase)
#endif // SVGRECTTRANLATION_H
