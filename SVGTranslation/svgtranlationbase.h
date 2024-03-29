﻿/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：svg模块图元转换基类
 * 修改记录：
***********************************************/

#ifndef SVGTRANLATIONBASE_H
#define SVGTRANLATIONBASE_H

#include <QString>

#include "sbreflex.h"

class SBShape;
class QXmlStreamWriter;
class SVGTranlationBase
{
public:
    SVGTranlationBase();
    virtual void exportShape(SBShape *shape) = 0;
    virtual QString typeName() const = 0;
    inline void setPWriter(QXmlStreamWriter *writer) { m_pWriter = writer; }

protected:
    QXmlStreamWriter *m_pWriter;
};

#endif // SVGTRANLATIONBASE_H
