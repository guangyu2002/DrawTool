#include "sbcanvas.h"
#include "sbediteventholder.h"

SBCanvas::SBCanvas(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
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

void SBCanvas::paintEvent(QPaintEvent *event)
{
    m_pEventHolder->paintEvent(event);
}
