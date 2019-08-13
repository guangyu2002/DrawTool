﻿/**********************************************
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
class QPainter;
class SBCanvas;
class SBSHAPESHARED_EXPORT SBEventHolder
{
public:
    SBEventHolder(SBCanvas *canvas);
    virtual ~SBEventHolder();
    virtual void mouseDownEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseUpEvent(QMouseEvent *);
    virtual void mouseDoubleClickEvent(QMouseEvent *);
    virtual void keyDownEvent(QKeyEvent *);
    virtual void keyUpEvent(QKeyEvent *);
    virtual void paintEvent(QPainter &, QPaintEvent *);
protected:
    SBCanvas *m_pCurrentCanvas;
};

#endif // SBEVENTHOLDER_H
