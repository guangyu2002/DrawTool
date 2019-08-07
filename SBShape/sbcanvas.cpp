#include "sbcanvas.h"
#include "sbediteventholder.h"
#include "sbshape.h"

#include <QPainter>

SBCanvas::SBCanvas(QWidget *parent) :
    QWidget(parent),
    m_dSBDocument(),
    m_dScaleGlobal_x(1),
    m_dScaleGlobal_y(1)
{
    setMouseTracking(true);//开始鼠标move事件捕捉能力
    setFocusPolicy(Qt::StrongFocus);//开启键盘事件捕捉能力
    m_pEventHolder = new SBEditEventHolder();
}

SBCanvas::~SBCanvas()
{
    if (m_pEventHolder != nullptr)
    {
        delete m_pEventHolder;
    }
    m_pEventHolder = nullptr;
}

void SBCanvas::setEventHolder(SBEventHolder *eventHolder)
{
    if (m_pEventHolder != nullptr)
    {
        delete  m_pEventHolder;
    }
    m_pEventHolder = eventHolder;
}

void SBCanvas::mousePressEvent(QMouseEvent *event)
{
    m_pEventHolder->mouseDownEvent(event);
}

void SBCanvas::mouseReleaseEvent(QMouseEvent *event)
{
    m_pEventHolder->mouseUpEvent(event);
}

void SBCanvas::mouseDoubleClickEvent(QMouseEvent *event)
{
    m_pEventHolder->mouseDoubleClickEvent(event);
}

void SBCanvas::mouseMoveEvent(QMouseEvent *event)
{
    m_pEventHolder->mouseMoveEvent(event);
}

void SBCanvas::keyPressEvent(QKeyEvent *event)
{
    m_pEventHolder->keyDownEvent(event);
}

void SBCanvas::keyReleaseEvent(QKeyEvent *event)
{
    m_pEventHolder->keyUpEvent(event);
}
/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：画布绘制函数，先进行文档图元绘制，再进行事件处理器中的绘制部分
 * 修改记录：
***********************************************/
void SBCanvas::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setRenderHints(QPainter::Antialiasing);//反走样抗锯齿
    p.scale(m_dScaleGlobal_x, m_dScaleGlobal_y);//画布全局缩放
    //p.translate(x, y);//画布全局移动
    QList<SBShape*>::iterator itor = m_dSBDocument.shapeList().begin();
    QList<SBShape*>::iterator itorEnd = m_dSBDocument.shapeList().end();
    while (itor != itorEnd)
    {
        (*itor)->draw(&p);
        itor++;
    }
    m_pEventHolder->paintEvent(event);
}
