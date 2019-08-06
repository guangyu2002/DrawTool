/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：画布事件处理器基类
 * 修改记录：
***********************************************/

#ifndef SBEVENTHOLDER_H
#define SBEVENTHOLDER_H

#include "sbshape_global.h"

class QMouseEvent;
class QKeyEvent;
class QPaintEvent;
class SBSHAPESHARED_EXPORT SBEventHolder
{
public:
    SBEventHolder();
    virtual void mouseDownEvent(QMouseEvent *e) = 0;
    virtual void mouseMoveEvent(QMouseEvent *e) = 0;
    virtual void mouseUpEvent(QMouseEvent *e) = 0;
    virtual void mouseDoubleClickEvent(QMouseEvent *e) = 0;
    virtual void keyDownEvent(QKeyEvent *e) = 0;
    virtual void keyUpEvent(QKeyEvent *e) = 0;
    virtual void paintEvent(QPaintEvent *e) = 0;
};

#endif // SBEVENTHOLDER_H
