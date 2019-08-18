/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：直线创建事件处理器
 * 修改记录：
***********************************************/

#ifndef SBCREATELINEEVENTHOLDER_H
#define SBCREATELINEEVENTHOLDER_H

#include "sbcreatebaseeventholder.h"

class SBSHAPESHARED_EXPORT SBCreateLineEventHolder : public SBCreateBaseEventHolder
{
public:
    SBCreateLineEventHolder(SBICanvas *canvas);
    void mouseDownEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseUpEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
};

#endif // SBCREATELINEEVENTHOLDER_H
