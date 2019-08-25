#include "sbline.h"

#include <QPainter>

SBLine::SBLine() :
    SBSimpleShape()
{
    m_dFillType = SBSimpleShape::FillType::NoneFillType;
}

void SBLine::draw(QPainter &painter)
{
    QPen *p = pen();
    painter.setPen(*p);
    painter.drawLine(m_dBegin, m_dEnd);
    delete p;
}

QRect SBLine::dispBox() const
{
    return QRect(m_dBegin.x() - m_dStrokeWidth, m_dBegin.y() - m_dStrokeWidth, m_dEnd.x() - m_dBegin.x() + m_dStrokeWidth * 2, m_dEnd.y() - m_dBegin.y() + m_dStrokeWidth * 2);
}

QRect SBLine::rectBox() const
{
    return QRect(m_dBegin, m_dEnd);
}
