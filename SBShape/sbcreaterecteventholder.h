/**********************************************
 * 创建时间：2019.08.07
 * 作者：guangyu
 * 说明：矩形创建事件处理器
 * 修改记录：
***********************************************/

#ifndef SBCREATERECTEVENTHOLDER_H
#define SBCREATERECTEVENTHOLDER_H

#include "sbeventholder.h"

class SBRect;
class SBSHAPESHARED_EXPORT SBCreateRectEventHolder : public SBEventHolder
{
public:
    SBCreateRectEventHolder(SBCanvas *canvas);
    ~SBCreateRectEventHolder() override;
    void mouseDownEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseUpEvent(QMouseEvent *e) override;
    void paintEvent(QPainter &p, QPaintEvent *e) override;
private:
    SBRect *m_pSBRect;
};

#endif // SBCREATERECTEVENTHOLDER_H
