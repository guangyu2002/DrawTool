#include "sbcreaterecteventholder.h"
#include "sbrect.h"
#include "sbicanvas.h"
#include "sbdocument.h"

#include <QMouseEvent>

SBCreateRectEventHolder::SBCreateRectEventHolder(SBICanvas *canvas) :
    SBCreateBaseEventHolder(canvas)
{

}

void SBCreateRectEventHolder::mouseDownEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) //开始创建矩形图元
    {
        SBRect *rect = new SBRect();
        rect->setCanvas(m_pCurrentCanvas);
        rect->setBegin(e->pos());
        rect->setEnd(e->pos());
        m_pShape = rect;
    }
}

void SBCreateRectEventHolder::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        if (m_pShape != nullptr)
        {
            SBRect *rect = dynamic_cast<SBRect*>(m_pShape);
            QRect oldRect = rect->dispBox();
            rect->setEnd(e->pos());
            rect->reDraw(oldRect);
        }
    }
}

void SBCreateRectEventHolder::mouseUpEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        createEnd();
    }
}
