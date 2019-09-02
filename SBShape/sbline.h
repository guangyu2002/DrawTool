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
    inline QPoint begin() const { return m_dBegin; }
    inline void setBegin(const QPoint &begin) { m_dBegin = begin; }
    inline QPoint end() const { return m_dEnd; }
    inline void setEnd(const QPoint &end) { m_dEnd = end; }

    // SBShape interface
public:
    inline QString typeName() const Q_DECL_OVERRIDE { return "line"; }
    void draw(QPainter &p) Q_DECL_OVERRIDE;
    QRect rectBox() const Q_DECL_OVERRIDE;
    QRect dispBox() const Q_DECL_OVERRIDE;
    void setPositon(const QPoint &pos) Q_DECL_OVERRIDE;
    bool pick(const QPoint &pos) const Q_DECL_OVERRIDE;

private:
    QPoint m_dBegin;
    QPoint m_dEnd;
};

#endif // SBLINE_H
