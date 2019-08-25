#ifndef SVGLINETRANLATION_H
#define SVGLINETRANLATION_H

#include "svgsimpleshapetranslation.h"


class SBLine;
class SVGLineTranlation : public SVGSimpleShapeTranslation
{
public:
    SVGLineTranlation();

    // SVGTranlationBase interface
public:
    void exportShape(SBShape *shape) Q_DECL_OVERRIDE;
    inline QString typeName() const Q_DECL_OVERRIDE { return "line"; }
    void exportLine(SBLine *line);

};
REGISTERCLASS(SVGLineTranlation, SVGSimpleShapeTranslation, SVGTranlationBase)
#endif // SVGLINETRANLATION_H
