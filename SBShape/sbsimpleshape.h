/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：简单图元抽象类
 * 修改记录：
***********************************************/

#ifndef SBSIMPLESHAPE_H
#define SBSIMPLESHAPE_H

#include "sbshape.h"

#include <QColor>

class QPen;
class QBrush;
class SBSHAPESHARED_EXPORT SBSimpleShape : public SBShape
{
public:
    /**********************
     * 渐变类型
    **********************/
    enum FillType
    {
        NoneFillType,
        SolidFillType,
        LeftToRightFillType,
        RightToLeftFillType,
        TopToBottomFillType,
        BottomToTopFillType
    };
    SBSimpleShape();

    inline int strokeWidth() const { return m_dStrokeWidth; }
    virtual void setStrokeWidth(const int width);
    inline const QColor &penColor() const { return m_dPenColor; }
    virtual void setPenColor(const QColor &color);
    inline const QColor &brushColor() const { return m_dBrushColor; }
    virtual void setBrushColor(const QColor &color);
    inline const QColor &gradientColor() const { return m_dGradientColor; }
    virtual void setGradientColor(const QColor &color);
    inline const FillType &fillType() const { return m_dFillType; }
    virtual void setFillType(const FillType &fillType);
protected:
    QBrush *brush();
    QPen *pen();
protected:
    int m_dStrokeWidth;
    QColor m_dPenColor;
    QColor m_dBrushColor;
    QColor m_dGradientColor;
    FillType m_dFillType;
};

#endif // SBSIMPLESHAPE_H
