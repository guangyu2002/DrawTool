/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：simple图元svg转换类
 * 修改记录：
***********************************************/


#ifndef SVGSIMPLESHAPETRANSLATION_H
#define SVGSIMPLESHAPETRANSLATION_H

#include "svgtranlationbase.h"

class SBSimpleShape;
class SVGSimpleShapeTranslation : public SVGTranlationBase
{
public:
    SVGSimpleShapeTranslation();

    // SVGTranlationBase interface
public:
    inline QString typeName() const Q_DECL_OVERRIDE { return "SimpleShape"; }

protected:
    void exportFillAndStroke(SBSimpleShape *simpleShape);

};
REGISTERCLASS_ABSTRACT(SVGSimpleShapeTranslation, SVGTranlationBase, SVGTranlationBase)
#endif // SVGSIMPLESHAPETRANSLATION_H
