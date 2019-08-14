#include "sbrect.h"
#include <QPainter>

SBRect::SBRect() : SBSimpleShape()
{

}

void SBRect::draw(QPainter &p)
{
    QBrush brush(m_dBrushColor);
    p.fillRect(rect(), brush);
    QPen pen(m_dPenColor);
    pen.setWidth(m_dStrokeWidth);
    p.setPen(pen);
    p.drawRect(rect());
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

QRect SBRect::rect() const
{
    return QRect(m_dBegin, m_dEnd);
}
