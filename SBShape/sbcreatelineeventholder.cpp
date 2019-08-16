#include "sbcreatelineeventholder.h"
#include "sbline.h"

#include <QMouseEvent>

SBCreateLineEventHolder::SBCreateLineEventHolder(SBICanvas *canvas) :
    SBCreateBaseEventHolder(canvas)
{

}

void SBCreateLineEventHolder::mouseDownEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        SBLine *line = new SBLine();
        line->setBegin(e->pos());
        line->setEnd(e->pos());
        line->setCanvas(m_pCurrentCanvas);
        m_pShape = line;
    }
}

void SBCreateLineEventHolder::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        if (m_pShape != nullptr)
        {
            SBLine *line = dynamic_cast<SBLine*>(m_pShape);
            QRect oldRect = line->dispBox();
            line->setEnd(e->pos());
            line->reDraw(oldRect);
        }
    }
}

void SBCreateLineEventHolder::mouseUpEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        createEnd();
    }
}

