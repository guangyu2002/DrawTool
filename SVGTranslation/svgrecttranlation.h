/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：矩形图元svg转换类
 * 修改记录：
***********************************************/

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
