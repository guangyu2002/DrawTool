/**********************************************
 * 创建时间：2019.08.07
 * 作者：guangyu
 * 说明：创建型事件处理器基类
 * 修改记录：
***********************************************/

#ifndef SBCREATEBASEEVENTHOLDER_H
#define SBCREATEBASEEVENTHOLDER_H

#include "sbeventholder.h"

class SBShape;
class SBSHAPESHARED_EXPORT SBCreateBaseEventHolder : public SBEventHolder
{
public:
    SBCreateBaseEventHolder(SBICanvas *canvas);
    void paintEvent(QPainter &, QPaintEvent *) override;
protected:
    virtual void createEnd();
    SBShape *m_pShape;
};

#endif // SBCREATEBASEEVENTHOLDER_H
