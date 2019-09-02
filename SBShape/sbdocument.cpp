#include "sbdocument.h"
#include "sbshape.h"
#include "sbicanvas.h"

SBDocument::SBDocument() :
    m_listShapes(),
    m_dShapeMaxId(0),
    m_dRect(0,0,1000,1000),
    m_dBackColor(Qt::black)
{

}

SBDocument::~SBDocument()
{
    int count = m_listShapes.count();
    for (int i = 0; i < count; ++i)
    {
        if (m_listShapes[i] != nullptr)
        {
            delete m_listShapes[i];
        }
        m_listShapes[i] = nullptr;
    }
    m_listShapes.clear();
}

void SBDocument::addShape(SBShape *shape)
{
    m_listShapes.push_back(shape);
    shape->setDocument(this);
    shape->setCanvas(m_pCanvas);
    shape->setId(m_dShapeMaxId);
    m_dShapeMaxId++;
}

SBShape *SBDocument::pickShape(const QPoint &pt) const
{
    int count = m_listShapes.count();
    for (int i = 0; i < count; ++i)
    {
        if (m_listShapes[i]->pick(pt))
        {
            return m_listShapes[i];
        }
    }
    return nullptr;
}
