#include "sbcreaterecteventholder.h"
#include "sbrect.h"
#include <QMouseEvent>
#include "sbcanvas.h"
#include <QDebug>

SBCreateRectEventHolder::SBCreateRectEventHolder(SBCanvas *canvas) :
    SBEventHolder(canvas),
    m_pSBRect()
{

}

SBCreateRectEventHolder::~SBCreateRectEventHolder()
{
    if (m_pSBRect != nullptr)
    {
        delete m_pSBRect;
    }
    m_pSBRect = nullptr;
}

void SBCreateRectEventHolder::mouseDownEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) //开始创建矩形图元
    {
        m_pSBRect = new SBRect();
        m_pSBRect->setCanvas(m_pCurrentCanvas);
        m_pSBRect->setBegin(e->pos());
    }
}

void SBCreateRectEventHolder::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        if (m_pSBRect != nullptr)
        {
            QRect oldRect = m_pSBRect->rect();
            qDebug() << "oldRect" << oldRect;
            m_pSBRect->setEnd(e->pos());
            //m_pSBRect->reDraw();
            QRect newRect = m_pSBRect->rect();
            qDebug() << "newRect" << newRect;
            m_pCurrentCanvas->update(oldRect);
            m_pCurrentCanvas->update(newRect);
            //m_pCurrentCanvas->update();
        }
    }
}

void SBCreateRectEventHolder::mouseUpEvent(QMouseEvent *e)
{

}

void SBCreateRectEventHolder::paintEvent(QPainter &p, QPaintEvent *e)
{
    if (m_pSBRect != nullptr)
    {
        m_pSBRect->draw(p);
    }
}
