/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：图元工具类
 * 修改记录：
***********************************************/

#ifndef SBSHAPETOOLS_H
#define SBSHAPETOOLS_H

#include "sbshape_global.h"

#include <QList>

class QRect;
class SBShape;
class SBSHAPESHARED_EXPORT SBShapeTools
{
public:
    static SBShapeTools &getInstance();

    QRect allShapeRect(const QList<SBShape*> &listShapes) const;
private:
    SBShapeTools();
    SBShapeTools(const SBShapeTools &sbShapeTools) = delete;
    SBShapeTools &operator=(const SBShapeTools &sbShapeTools) = delete;
};

#endif // SBSHAPETOOLS_H
