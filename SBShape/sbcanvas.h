/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：画布类
 * 修改记录：
***********************************************/

#ifndef SBCANVAS_H
#define SBCANVAS_H

#include "sbshape_global.h"
#include "sbicanvas.h"

#include <QWidget>

class SBEventHolder;
class SBDocument;
class SBSHAPESHARED_EXPORT SBCanvas : public QWidget, public SBICanvas
{
    Q_OBJECT
public:
    explicit SBCanvas(QWidget *parent = nullptr);
    ~SBCanvas() Q_DECL_OVERRIDE;
    void setEventHolder(SBEventHolder *eventHolder);
    void eventHolderEnd() Q_DECL_OVERRIDE;
    inline const SBEventHolder *eventHolder() const { return m_pEventHolder; }
    inline SBDocument *doc() const override { return m_pSBDocument; }
    inline void reDraw(const QRect &rect) override { update(rect); }
protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

public slots:

private:
    SBEventHolder *m_pEventHolder;
    SBDocument *m_pSBDocument;
    double m_dScaleGlobal_x;
    double m_dScaleGlobal_y;
};

#endif // SBCANVAS_H
