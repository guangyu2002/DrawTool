#include "sbshapetools.h"
#include "sbshape.h"

SBShapeTools &SBShapeTools::getInstance()
{
    static SBShapeTools instance;
    return instance;
}

QRect SBShapeTools::allShapeRect(const QList<SBShape*> &listShapes) const
{
    QRect allRect;
    int count = listShapes.count();
    for (int i = 0; i < count; ++i)
    {
        allRect = allRect.united(listShapes[i]->rectBox());
    }
    return allRect;
}

SBShapeTools::SBShapeTools()
{

}
