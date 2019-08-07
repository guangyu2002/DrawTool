/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：矩形类
 * 修改记录：
***********************************************/

#ifndef SBRECT_H
#define SBRECT_H

#include "sbshape.h"

#include <QPoint>

class SBSHAPESHARED_EXPORT SBRect : public SBShape
{
public:
    SBRect();

    void draw(QPainter *p) override;

    inline const QPoint &begin() const { return m_dBegin; }
    inline void setBegin(const QPoint &pt) { m_dBegin = pt; }
    inline const QPoint &end() const { return m_dEnd; }
    inline void setEnd(const QPoint &pt) { m_dEnd = pt; }

private:
    QPoint m_dBegin;
    QPoint m_dEnd;
};

#endif // SBRECT_H
