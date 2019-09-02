#include "sbediteventholder.h"
#include "sbshape.h"
#include "sbdocument.h"
#include "sbicanvas.h"

SBEditEventHolder::SBEditEventHolder(SBICanvas *canvas) :
    SBEventHolder(canvas),
    m_dSelectedShapes()
{

}

void SBEditEventHolder::mouseDownEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_dSelectedShapes.clear();
        SBShape *shape = m_pCurrentCanvas->doc()->pickShape(e->pos());
        if (shape != nullptr)
        {
            m_dSelectedShapes.push_back(shape);
        }
    }
}

void SBEditEventHolder::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        int count = m_dSelectedShapes.count();
        for (int i = 0; i < count; ++i)
        {
            QRect oldRect = m_dSelectedShapes[i]->dispBox();
            m_dSelectedShapes[i]->setPositon(e->pos());
            m_dSelectedShapes[i]->reDraw(oldRect);
        }
    }
}

void SBEditEventHolder::mouseUpEvent(QMouseEvent *e)
{

}

void SBEditEventHolder::mouseDoubleClickEvent(QMouseEvent *e)
{

}

void SBEditEventHolder::keyDownEvent(QKeyEvent *)
{

}

void SBEditEventHolder::keyUpEvent(QKeyEvent *)
{

}

void SBEditEventHolder::paintEvent(QPainter &, QPaintEvent *)
{

}
