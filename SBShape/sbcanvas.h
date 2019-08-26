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

#include <QScrollArea>

class SBEventHolder;
class SBDocument;
class SBCanvas;
/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：画布内部类，实现绘制的载体
 * 修改记录：
***********************************************/
class SBInternalCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit SBInternalCanvas(SBCanvas *canvas, QWidget *parent = nullptr);
    virtual void reDraw(const QRect &rect);
protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    double m_dScaleGlobal;
    SBCanvas *m_pParentCanvas;

    friend class SBCanvas;
};
/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：画布类,是一个滚动条控件,内部加载一个SBInternalCanvas
 * 修改记录：
***********************************************/
class SBSHAPESHARED_EXPORT SBCanvas : public QScrollArea, public SBICanvas
{
    Q_OBJECT
public:
    explicit SBCanvas(QWidget *parent = nullptr);
    ~SBCanvas() Q_DECL_OVERRIDE;
    void setEventHolder(SBEventHolder *eventHolder);
    void eventHolderEnd() Q_DECL_OVERRIDE;
    inline SBEventHolder *eventHolder() const { return m_pEventHolder; }
    inline SBDocument *doc() const override { return m_pSBDocument; }
    void reDraw(const QRect &rect) override;
    void setCanvasScale(double scale);
    double canvasScale();
private:
    void scrollAreaInit();
signals:

public slots:

private:
    SBEventHolder *m_pEventHolder;
    SBDocument *m_pSBDocument;
    SBInternalCanvas *m_pInternalCanvas;

};

#endif // SBCANVAS_H
