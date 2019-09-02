/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：画布编辑态事件处理器
 * 修改记录：
***********************************************/

#ifndef SBEDITEVENTHOLDER_H
#define SBEDITEVENTHOLDER_H

#include "sbeventholder.h"

#include <QList>

class SBShape;
class SBSHAPESHARED_EXPORT SBEditEventHolder : public SBEventHolder
{
public:
    SBEditEventHolder(SBICanvas *canvas);
    void mouseDownEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseUpEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void keyDownEvent(QKeyEvent *e) Q_DECL_OVERRIDE;
    void keyUpEvent(QKeyEvent *e) Q_DECL_OVERRIDE;
    void paintEvent(QPainter &, QPaintEvent *e) Q_DECL_OVERRIDE;

protected:
    QList<SBShape*> m_dSelectedShapes;
};

#endif // SBEDITEVENTHOLDER_H
