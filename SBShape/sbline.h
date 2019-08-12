/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：直线类
 * 修改记录：
***********************************************/

#ifndef SBLINE_H
#define SBLINE_H

#include "sbshape.h"

class SBSHAPESHARED_EXPORT SBLine : public SBShape
{
public:
    SBLine();
    void draw(QPainter &p) override;
};

#endif // SBLINE_H
