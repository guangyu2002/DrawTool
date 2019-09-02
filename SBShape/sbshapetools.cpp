#include "sbshapetools.h"
#include "sbshape.h"

SBShapeTools &SBShapeTools::getInstance()
{
    static SBShapeTools instance;
    return instance;
}

QRect SBShapeTools::allShapeDispBox(const QList<SBShape*> &listShapes) const
{
    QRect allDispBpx;
    int count = listShapes.count();
    for (int i = 0; i < count; ++i)
    {
        allDispBpx = allDispBpx.united(listShapes[i]->dispBox());
    }
    return allDispBpx;
}

SBShapeTools::SBShapeTools()
{

}
