#include "sbcreaterecteventholder.h"
#include "sbrect.h"

SBCreateRectEventHolder::SBCreateRectEventHolder() :
    SBEventHolder(),
    m_pSBRect()
{

}

void SBCreateRectEventHolder::mouseDownEvent(QMouseEvent *e)
{

}

void SBCreateRectEventHolder::mouseMoveEvent(QMouseEvent *e)
{

}

void SBCreateRectEventHolder::mouseUpEvent(QMouseEvent *e)
{

}

void SBCreateRectEventHolder::paintEvent(QPainter &, QPaintEvent *e)
{
    if (m_pSBRect != nullptr)
    {
        m_pSBRect->draw();
    }
}
