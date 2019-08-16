#include "sbcreatebaseeventholder.h"
#include "sbshape.h"
#include "sbdocument.h"
#include "sbicanvas.h"

SBCreateBaseEventHolder::SBCreateBaseEventHolder(SBICanvas *canvas) :
    SBEventHolder(canvas)
{

}

void SBCreateBaseEventHolder::paintEvent(QPainter &p, QPaintEvent *)
{
    if (m_pShape != nullptr)
    {
        m_pShape->draw(p);
    }
}

void SBCreateBaseEventHolder::createEnd()
{
    if (m_pShape != nullptr)
    {
        m_pCurrentCanvas->doc()->addShape(m_pShape);
    }
    m_pCurrentCanvas->eventHolderEnd();
}
