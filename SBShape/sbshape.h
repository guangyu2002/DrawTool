/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：图元基类
 * 修改记录：
***********************************************/

#ifndef SBSHAPE_H
#define SBSHAPE_H

#include "sbshape_global.h"

class QPainter;
class SBSHAPESHARED_EXPORT SBShape
{

public:
    SBShape();

    virtual void draw(QPainter *p) = 0;
};

#endif // SBSHAPE_H
