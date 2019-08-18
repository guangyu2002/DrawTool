/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：图元基类
 * 修改记录：
***********************************************/

#ifndef SBSHAPE_H
#define SBSHAPE_H

#include "sbshape_global.h"

#include <QString>

class QRect;
class QPainter;
class SBICanvas;
class SBDocument;
class SBSHAPESHARED_EXPORT SBShape
{

public:
    SBShape();
    virtual ~SBShape();
    virtual void draw(QPainter &p) = 0;
    virtual void reDraw();
    virtual void reDraw(QRect &rect);
    virtual QRect rectBox() const = 0;
    virtual QRect dispBox() const = 0;
    virtual QString typeName() const;
    inline SBDocument *document() const { return m_pDocument; }
    inline void setDocument(SBDocument *doc) { m_pDocument = doc; }
    inline SBICanvas *canvas() const { return m_pCanvas; }
    inline void setCanvas(SBICanvas *canvas) { m_pCanvas = canvas; }

private:
    SBICanvas *m_pCanvas;
    SBDocument *m_pDocument;
};

#endif // SBSHAPE_H
