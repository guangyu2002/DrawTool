/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：画布编辑态事件处理器
 * 修改记录：
***********************************************/

#ifndef SBEDITEVENTHOLDER_H
#define SBEDITEVENTHOLDER_H

#include "sbeventholder.h"

class SBSHAPESHARED_EXPORT SBEditEventHolder : public SBEventHolder
{
public:
    SBEditEventHolder();
    void mouseDownEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseUpEvent(QMouseEvent *e) override;
    void mouseDoubleClickEvent(QMouseEvent *e) override;
    void keyDownEvent(QKeyEvent *e) override;
    void keyUpEvent(QKeyEvent *e) override;
    void paintEvent(QPainter &, QPaintEvent *e) override;
};

#endif // SBEDITEVENTHOLDER_H
