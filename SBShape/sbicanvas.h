/**********************************************
 * 创建时间：2019.08.13
 * 作者：guangyu
 * 说明：画布接口
 * 修改记录：
***********************************************/

#ifndef SBICANVAS_H
#define SBICANVAS_H

class QRect;
class SBICanvas
{
public:
    SBICanvas();

    virtual void reDraw(const QRect &rect) = 0;
};

#endif // SBICANVAS_H
