#ifndef SVGRECTTRANLATION_H
#define SVGRECTTRANLATION_H

#include "svgsimpleshapetranslation.h"

class SVGRectTranlation : public SVGSimpleShapeTranslation
{
public:
    SVGRectTranlation();

    // SVGTranlationBase interface
public:
    void exportShape(SBShape *shape) Q_DECL_OVERRIDE;
    inline QString typeName() const Q_DECL_OVERRIDE { return "rect"; }
};

#endif // SVGRECTTRANLATION_H
