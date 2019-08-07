/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：画布类
 * 修改记录：
***********************************************/

#ifndef SBCANVAS_H
#define SBCANVAS_H

#include "sbshape_global.h"

#include <QWidget>

class SBEventHolder;
class SBSHAPESHARED_EXPORT SBCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit SBCanvas(QWidget *parent = nullptr);
    ~SBCanvas() override;
    void setEventHolder(SBEventHolder *eventHolder);
    inline SBEventHolder *eventHolder() const { return m_pEventHolder; }
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
};

#endif // SBCANVAS_H
