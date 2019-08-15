#include "sbshape.h"
#include "sbicanvas.h"
#include <QRect>

SBShape::SBShape()
{
}

void SBShape::reDraw()
{
    if (m_pCanvas != nullptr)
    {
        m_pCanvas->reDraw(dispBox());
    }
}

void SBShape::reDraw(QRect &rect)
{
    if (m_pCanvas != nullptr)
    {
        m_pCanvas->reDraw(rect);
        m_pCanvas->reDraw(dispBox());
    }
}
