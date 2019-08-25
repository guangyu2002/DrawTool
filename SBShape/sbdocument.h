/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：文档类,文档中存储了图元集合
 * 修改记录：
***********************************************/

#ifndef SBDOCUMENT_H
#define SBDOCUMENT_H

#include "sbshape_global.h"

#include <QList>
#include <QColor>


class SBShape;
class SBICanvas;
class SBSHAPESHARED_EXPORT SBDocument
{
public:
    SBDocument();
    ~SBDocument();
    void addShape(SBShape *shape);

    inline QList<SBShape*> &shapeList() { return  m_listShapes; }
    inline void setCanvas(SBICanvas *canvas) { m_pCanvas = canvas; }
    inline const QRect &rect() const { return m_dRect; }

    inline const QColor &backColor() const { return m_dBackColor; }

private:
    QList<SBShape*> m_listShapes;
    SBICanvas *m_pCanvas;
    int m_dShapeMaxId;
    QRect m_dRect;
    QColor m_dBackColor;
};

#endif // SBDOCUMENT_H
