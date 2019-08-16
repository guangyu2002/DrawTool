﻿/**********************************************
 * 创建时间：2019.08.07
 * 作者：guangyu
 * 说明：矩形创建事件处理器
 * 修改记录：
***********************************************/

#ifndef SBCREATERECTEVENTHOLDER_H
#define SBCREATERECTEVENTHOLDER_H

#include "sbcreatebaseeventholder.h"

class SBSHAPESHARED_EXPORT SBCreateRectEventHolder : public SBCreateBaseEventHolder
{
public:
    SBCreateRectEventHolder(SBICanvas *canvas);
    void mouseDownEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseUpEvent(QMouseEvent *e) override;
};

#endif // SBCREATERECTEVENTHOLDER_H
