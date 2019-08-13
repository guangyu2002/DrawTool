/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：画布类
 * 修改记录：
***********************************************/

#ifndef SBCANVAS_H
#define SBCANVAS_H

#include "sbshape_global.h"
#include "sbdocument.h"
#include "sbicanvas.h"

#include <QWidget>

class SBEventHolder;
class SBSHAPESHARED_EXPORT SBCanvas : public QWidget, public SBICanvas
{
    Q_OBJECT
public:
    explicit SBCanvas(QWidget *parent = nullptr);
    ~SBCanvas() override;
    void setEventHolder(SBEventHolder *eventHolder);
    inline const SBEventHolder *eventHolder() const { return m_pEventHolder; }
    inline void reDraw(const QRect &rect) override { update(rect); }
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:

private:
    SBEventHolder *m_pEventHolder;
    SBDocument m_dSBDocument;
    double m_dScaleGlobal_x;
    double m_dScaleGlobal_y;
};

#endif // SBCANVAS_H
