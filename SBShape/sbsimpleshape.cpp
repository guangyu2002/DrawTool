#include "sbsimpleshape.h"

SBSimpleShape::SBSimpleShape() :
    m_dStrokeWidth(20),
    m_dPenColor(Qt::red),
    m_dBrushColor(Qt::blue)
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

