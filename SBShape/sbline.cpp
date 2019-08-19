#include "sbline.h"

#include <QPainter>

SBLine::SBLine()
{

}

void SBLine::draw(QPainter &p)
{
    QPen pen(m_dPenColor);
    pen.setWidth(m_dStrokeWidth);
    p.setPen(pen);
    p.drawLine(m_dBegin, m_dEnd);
}

QRect SBLine::dispBox() const
{
    return QRect(m_dBegin.x() - m_dStrokeWidth, m_dBegin.y() - m_dStrokeWidth, m_dEnd.x() - m_dBegin.x() + m_dStrokeWidth * 2, m_dEnd.y() - m_dBegin.y() + m_dStrokeWidth * 2);
}

QRect SBLine::rectBox() const
{
    return QRect(m_dBegin, m_dEnd);
}
