/**********************************************
 * 创建时间：2019.08.13
 * 作者：guangyu
 * 说明：画布接口
 * 修改记录：
***********************************************/

#ifndef SBICANVAS_H
#define SBICANVAS_H

#include "sbshape_global.h"

class QRect;
class SBDocument;
class SBSHAPESHARED_EXPORT SBICanvas
{
public:
    SBICanvas();
    virtual SBDocument *doc() const = 0;
    virtual void reDraw(const QRect &rect) = 0;
    virtual void eventHolderEnd();
};

#endif // SBICANVAS_H
