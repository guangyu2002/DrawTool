#include "sbsimpleshape.h"

#include <QPen>
#include <QBrush>

SBSimpleShape::SBSimpleShape() :
    SBShape(),
    m_dStrokeWidth(20),
    m_dPenColor(Qt::red),
    m_dBrushColor(Qt::blue),
    m_dFillType(FillType::SolidFillType)
{

}

void SBSimpleShape::setStrokeWidth(const int width)
{
    m_dStrokeWidth = width;
}

void SBSimpleShape::setPenColor(const QColor &color)
{
    m_dPenColor = color;
}

void SBSimpleShape::setBrushColor(const QColor &color)
{
    m_dBrushColor = color;
}

void SBSimpleShape::setGradientColor(const QColor &color)
{
    m_dGradientColor = color;
}

void SBSimpleShape::setFillType(const FillType &fillType)
{
    m_dFillType = fillType;
}

QPen *SBSimpleShape::pen()
{
    QPen *p = new QPen();
    p->setWidth(m_dStrokeWidth);
    p->setColor(m_dPenColor);
    return p;
}


QBrush *SBSimpleShape::brush()
{
    QRect rect = rectBox();
    switch (m_dFillType)
    {
        case FillType::NoneFillType:
        {
            QBrush *b = new QBrush();
            b->setStyle(Qt::BrushStyle::NoBrush);
            return b;
        }
        case FillType::SolidFillType:
        {
            QBrush *b = new QBrush();
            b->setStyle(Qt::BrushStyle::SolidPattern);
            b->setColor(m_dBrushColor);
            return b;
        }
        case FillType::LeftToRightFillType:
        case FillType::RightToLeftFillType:
        case FillType::TopToBottomFillType:
        case FillType::BottomToTopFillType:
        {
            QPointF startPt, endPt;
            if (m_dFillType == FillType::LeftToRightFillType)
            {
                startPt = rect.topLeft();
                endPt = rect.topRight();
            }
            else if (m_dFillType == FillType::RightToLeftFillType)
            {
                startPt = rect.topRight();
                endPt = rect.topLeft();
            }
            else if (m_dFillType == FillType::TopToBottomFillType)
            {
                startPt = rect.topLeft();
                endPt = rect.bottomLeft();
            }
            else if (m_dFillType == FillType::BottomToTopFillType)
            {
                startPt = rect.bottomLeft();
                endPt = rect.topLeft();
            }
            QLinearGradient gradient(startPt, endPt);
            gradient.setColorAt(0, m_dBrushColor);
            gradient.setColorAt(1,m_dGradientColor);
            QBrush *b = new QBrush(gradient);
            return b;
        }
        default:
            return nullptr;
    }

}

