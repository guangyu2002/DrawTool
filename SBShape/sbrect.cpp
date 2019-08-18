#include "sbrect.h"
#include <QPainter>

SBRect::SBRect() : SBSimpleShape()
{

}

void SBRect::draw(QPainter &p)
{
    QBrush brush(m_dBrushColor);
    p.fillRect(rectBox(), brush);
    QPen pen(m_dPenColor);
    pen.setWidth(m_dStrokeWidth);
    p.setPen(pen);
    p.drawRect(rectBox());
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
/*********************************************************************
 * 元件刷新区域，元件实际的绘制区域是rectBox的基础上加上膨胀值m_dStrokeWidth / 2
 * 此处使用膨胀值m_dStrokeWidth，是为了在创建矩形时鼠标移动不会造成矩形边缘闪烁
*********************************************************************/
QRect SBRect::dispBox() const
{
    return QRect(m_dBegin.x() - m_dStrokeWidth, m_dBegin.y() - m_dStrokeWidth, width() + m_dStrokeWidth * 2, height() + m_dStrokeWidth * 2);
}

QString SBRect::typeName()
{
    return "rect";
}

QRect SBRect::rectBox() const
{
    return QRect(m_dBegin, m_dEnd);
}
