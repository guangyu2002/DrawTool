/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：直线类
 * 修改记录：
***********************************************/

#ifndef SBLINE_H
#define SBLINE_H

#include "sbsimpleshape.h"

#include <QPoint>

class SBSHAPESHARED_EXPORT SBLine : public SBSimpleShape
{
public:
    SBLine();
    void draw(QPainter &p) override;
    QRect rect() const override;
private:
    QPoint m_dBegin;
    QPoint m_dEnd;
};

#endif // SBLINE_H
