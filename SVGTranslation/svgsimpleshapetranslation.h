/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：simple图元svg转换类
 * 修改记录：
***********************************************/


#ifndef SVGSIMPLESHAPETRANSLATION_H
#define SVGSIMPLESHAPETRANSLATION_H

#include "svgtranlationbase.h"

class SVGSimpleShapeTranslation : public SVGTranlationBase
{
public:
    SVGSimpleShapeTranslation();

    // SVGTranlationBase interface
public:
    void exportShape(SBShape *shape) Q_DECL_OVERRIDE;
    inline QString typeName() const Q_DECL_OVERRIDE { return "SimpleShape"; }

    // SVGTranlationBase interface
public:
    void exportShapeAfter(SBShape *shape) Q_DECL_OVERRIDE;
    void exportShapeBefore(SBShape *shape) Q_DECL_OVERRIDE;
};
REGISTERCLASS(SVGSimpleShapeTranslation, SVGTranlationBase, SVGTranlationBase)
#endif // SVGSIMPLESHAPETRANSLATION_H
