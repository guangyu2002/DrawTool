#include "sbdocument.h"
#include "sbshape.h"
#include "sbicanvas.h"

SBDocument::SBDocument() :
    m_listShapes()
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
}
