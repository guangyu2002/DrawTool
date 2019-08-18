/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：svg模块图元转换基类
 * 修改记录：
***********************************************/

#ifndef SVGTRANLATIONBASE_H
#define SVGTRANLATIONBASE_H

#include <QString>

class SBShape;
class SVGTranlationBase
{
public:
    SVGTranlationBase();
    virtual void exportShape(SBShape *shape);

    virtual QString typeName() const;
};

#endif // SVGTRANLATIONBASE_H
