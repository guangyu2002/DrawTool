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
    p = nullptr;
}

QRect SBLine::dispBox() const
{
    int w = m_dStrokeWidth / 2;
    return QRect(m_dBegin.x() - w, m_dBegin.y() - w, m_dEnd.x() - m_dBegin.x() + m_dStrokeWidth, m_dEnd.y() - m_dBegin.y() + m_dStrokeWidth);
}

void SBLine::setPositon(const QPoint &pos)
{

}

bool SBLine::pick(const QPoint &pos) const
{
    return false;
}

QRect SBLine::rectBox() const
{
    return QRect(m_dBegin.x(), m_dBegin.y(), m_dEnd.x() - m_dBegin.x(), m_dEnd.y() - m_dBegin.y());
}
