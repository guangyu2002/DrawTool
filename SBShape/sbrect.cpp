#include "sbrect.h"
#include <QPainter>

SBRect::SBRect()
{

}

void SBRect::draw(QPainter &p)
{
    QPen pen(Qt::red);
    p.setPen(pen);
    p.drawRect(m_dBegin.x(),m_dBegin.y(), width(), height());
}

int SBRect::width() const
{
    return m_dEnd.x() - m_dBegin.x();
}

void SBRect::setWidth(const int width)
{
    m_dEnd.setX(m_dBegin.x() + width);
}

int SBRect::height() const
{
    return  m_dEnd.y() - m_dBegin.y();
}

void SBRect::setHeight(const int height)
{
    m_dEnd.setY(m_dBegin.y() + height);
}
