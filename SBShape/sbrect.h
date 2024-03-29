﻿/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：矩形类
 * 修改记录：
***********************************************/

#ifndef SBRECT_H
#define SBRECT_H

#include "sbsimpleshape.h"

#include <QPoint>

class SBSHAPESHARED_EXPORT SBRect : public SBSimpleShape
{
public:
    SBRect();
    inline const QPoint &begin() const { return m_dBegin; }
    inline void setBegin(const QPoint &pt) { m_dBegin = pt; }
    inline const QPoint &end() const { return m_dEnd; }
    inline void setEnd(const QPoint &pt) { m_dEnd = pt; }
    int width() const;
    void setWidth(const int width);
    int height() const;
    void setHeight(const int height);

    // SBShape interface
public:
    inline QString typeName() const Q_DECL_OVERRIDE { return "rect"; }
    void draw(QPainter &p) Q_DECL_OVERRIDE;
    QRect rectBox() const Q_DECL_OVERRIDE;
    QRect dispBox() const Q_DECL_OVERRIDE;
    void setPositon(const QPoint &pos) Q_DECL_OVERRIDE;
    bool pick(const QPoint &pos) const Q_DECL_OVERRIDE;

protected:
    QPoint m_dBegin;
    QPoint m_dEnd;
};

#endif // SBRECT_H
