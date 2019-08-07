/**********************************************
 * 创建时间：2019.08.07
 * 作者：guangyu
 * 说明：矩形创建事件处理器
 * 修改记录：
***********************************************/

#ifndef SBCREATERECTEVENTHOLDER_H
#define SBCREATERECTEVENTHOLDER_H

#include "sbeventholder.h"

class SBSHAPESHARED_EXPORT SBCreateRectEventHolder : public SBEventHolder
{
public:
    SBCreateRectEventHolder();
    void mouseDownEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseUpEvent(QMouseEvent *e);
};

#endif // SBCREATERECTEVENTHOLDER_H
