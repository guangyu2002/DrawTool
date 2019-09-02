#include "sbrect.h"
#include <QPainter>

SBRect::SBRect() :
    SBSimpleShape(),
    m_dBegin(),
    m_dEnd()
{

}

void SBRect::draw(QPainter &painter)
{
    QBrush *b = brush();
    painter.fillRect(rectBox(), *b);
    QPen *p = pen();
    painter.setPen(*p);
    painter.drawRect(rectBox());
    delete b;
    b = nullptr;
    delete p;
    p = nullptr;
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
    return m_dEnd.y() - m_dBegin.y();
}

void SBRect::setHeight(const int height)
{
    m_dEnd.setY(m_dBegin.y() + height);
}
/*********************************************************************
 * 元件刷新区域，元件实际的绘制区域是rectBox的基础上加上膨胀值m_dStrokeWidth
*********************************************************************/
QRect SBRect::dispBox() const
{
    int w = m_dStrokeWidth / 2;
    return QRect(m_dBegin.x() - w, m_dBegin.y() - w, width() + m_dStrokeWidth, height() + m_dStrokeWidth);
}

void SBRect::setPositon(const QPoint &pos)
{
    QPoint pt = pos - m_dBegin;
    setBegin(pos);
    setEnd(pt + m_dEnd);
}

bool SBRect::pick(const QPoint &pos) const
{
    return rectBox().contains(pos);
}


QRect SBRect::rectBox() const
{
    return QRect(m_dBegin.x(), m_dBegin.y(), m_dEnd.x() - m_dBegin.x(), m_dEnd.y() - m_dBegin.y());
}
