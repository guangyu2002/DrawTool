#include "sbcanvas.h"
#include "sbediteventholder.h"
#include "sbshape.h"
#include "sbdocument.h"

#include <QPainter>
#include <QScrollBar>

SBInternalCanvas::SBInternalCanvas(SBCanvas *canvas, QWidget *parent) :
    QWidget(parent),
    m_dScaleGlobal(1),
    m_pParentCanvas(canvas)
{
    setMouseTracking(true);//开始鼠标move事件捕捉能力
    setFocusPolicy(Qt::StrongFocus);//开启键盘事件捕捉能力
}

void SBInternalCanvas::reDraw(const QRect &rect)
{
    update(rect.x()- m_pParentCanvas->horizontalScrollBar()->value(), rect.y()- m_pParentCanvas->verticalScrollBar()->value(), rect.width(), rect.height());
}

void SBInternalCanvas::mousePressEvent(QMouseEvent *event)
{
    m_pParentCanvas->eventHolder()->mouseDownEvent(event);
}

void SBInternalCanvas::mouseReleaseEvent(QMouseEvent *event)
{
    m_pParentCanvas->eventHolder()->mouseUpEvent(event);
}

void SBInternalCanvas::mouseDoubleClickEvent(QMouseEvent *event)
{
    m_pParentCanvas->eventHolder()->mouseDoubleClickEvent(event);
}

void SBInternalCanvas::mouseMoveEvent(QMouseEvent *event)
{
    m_pParentCanvas->eventHolder()->mouseMoveEvent(event);
}

void SBInternalCanvas::keyPressEvent(QKeyEvent *event)
{
    m_pParentCanvas->eventHolder()->keyDownEvent(event);
}

void SBInternalCanvas::keyReleaseEvent(QKeyEvent *event)
{
    m_pParentCanvas->eventHolder()->keyUpEvent(event);
}
/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：画布绘制函数，先进行文档图元绘制，再进行事件处理器中的绘制部分
 * 修改记录：
***********************************************/
void SBInternalCanvas::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setRenderHints(QPainter::Antialiasing);//反走样抗锯齿
    p.scale(m_dScaleGlobal, m_dScaleGlobal);//画布全局缩放
    //p.translate(x, y);//画布全局移动
    QList<SBShape*>::iterator itor = m_pParentCanvas->doc()->shapeList().begin();
    QList<SBShape*>::iterator itorEnd = m_pParentCanvas->doc()->shapeList().end();
    while (itor != itorEnd)
    {
        (*itor)->draw(p);
        itor++;
    }
    m_pParentCanvas->eventHolder()->paintEvent(p, event);
}

SBCanvas::SBCanvas(QWidget *parent) :
    QScrollArea(parent)
{
    m_pEventHolder = new SBEditEventHolder(this);
    m_pSBDocument = new SBDocument();
    m_pSBDocument->setCanvas(this);
    m_pInternalCanvas = new SBInternalCanvas(this);
    m_pInternalCanvas->setMinimumSize(m_pSBDocument->rect().size());
    scrollAreaInit();
}

SBCanvas::~SBCanvas()
{
    if (m_pEventHolder != nullptr)
    {
        delete m_pEventHolder;
    }
    m_pEventHolder = nullptr;
    if (m_pSBDocument != nullptr)
    {
        delete m_pSBDocument;
    }
    m_pSBDocument = nullptr;
}

void SBCanvas::setEventHolder(SBEventHolder *eventHolder)
{
    if (m_pEventHolder != nullptr)
    {
        delete  m_pEventHolder;
    }
    m_pEventHolder = eventHolder;
}

void SBCanvas::eventHolderEnd()
{
    SBEventHolder *eventHolder = new SBEditEventHolder(this);
    setEventHolder(eventHolder);
}

void SBCanvas::reDraw(const QRect &rect)
{
    m_pInternalCanvas->reDraw(rect);
}

void SBCanvas::setCanvasScale(double scale)
{
    m_pInternalCanvas->m_dScaleGlobal = scale;
}

double SBCanvas::canvasScale()
{
    return m_pInternalCanvas->m_dScaleGlobal;
}

void SBCanvas::scrollAreaInit()
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setWidgetResizable(true);
    setWidget(m_pInternalCanvas);
}
