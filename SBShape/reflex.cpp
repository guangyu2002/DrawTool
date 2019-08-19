#include "reflex.h"

#include <QString>

Reflex::Reflex()
{

}
Reflex::~Reflex()
{

}

ClassFactory::ClassFactory()
{

}

Metadata * ClassFactory::GetMetadata(const QString &rootName)
{
    QList<Metadata*>::iterator itorBegin = m_dMetadataList.begin();
    QList<Metadata*>::iterator itorEnd = m_dMetadataList.end();
    while (itorBegin != itorEnd)
    {
        if ((*itorBegin)->GetRootName() == rootName)
        {
            return (*itorBegin);
        }
        itorBegin++;
    }
    return nullptr;
}

ClassFactory::~ClassFactory()
{
    QList<Metadata*>::iterator itorBegin = m_dMetadataList.begin();
    QList<Metadata*>::iterator itorEnd = m_dMetadataList.end();
    while (itorBegin != itorEnd)
    {
        if ((*itorBegin) != nullptr)
        {
            delete (*itorBegin);
        }
        itorBegin++;
    }
    m_dMetadataList.clear();
}

void ClassFactory::RegisterReflex(const QString &className, const QString &baseName, ReflexObject reflexObject, const QString &rootName)
{
    Metadata* metadata = GetMetadata(rootName);
    if (metadata == nullptr)
    {
        metadata = new Metadata(rootName);
        m_dMetadataList.push_back(metadata);
    }
    QHash<QString, ReflexObjectClass*>* reflexObjectClassHash = metadata->GetReflexObjects();
    QHash<QString, ReflexObjectClass*>::iterator it = reflexObjectClassHash->find(className);
    if (it != reflexObjectClassHash->end())
    {
        reflexObjectClassHash->operator[](className)->reflexObject = reflexObject;
    }
    else
    {
        if (reflexObject != nullptr)
        {
            reflexObjectClassHash->insert(className, new ReflexObjectClass(reflexObject));
        }
    }
    QHash<QString, QList<QString>>* inheritHash = metadata->GetInheritHash();
    QHash<QString, QList<QString>>::iterator itor = inheritHash->find(className);
    if (itor != inheritHash->end()) //找到了继承树，说明是一个类有多个反射基类，暂时不考虑
    {
        return;
    }
    itor = inheritHash->find(baseName);
    if (itor != inheritHash->end())
    {
        QList<QString> listName = itor.value();
        QList<QString> listNameNew;
        listNameNew.push_back(baseName);
        QList<QString>::iterator iter = listName.begin();
        QList<QString>::iterator iterEnd = listName.end();
        while (iter != iterEnd)
        {
            listNameNew.push_back(*iter);
            iter++;
        }
        inheritHash->insert(className, listNameNew);
    }
    else
    {
        bool isExit = false;
        QHash<QString, QList<QString>>::iterator itorBegin = inheritHash->begin();
        QHash<QString, QList<QString>>::iterator itorEnd = inheritHash->begin();
        while (itorBegin != itorEnd)
        {
            QList<QString> listName = itorBegin.value();
            QList<QString>::iterator iter = std::find(listName.begin(), listName.end(), className);
            if (iter != listName.end())
            {
                listName.insert(iter, baseName);
                isExit = true;
            }
            itorBegin++;
        }
        if (!isExit)
        {
            QList<QString> listBaseName;
            listBaseName.push_back(baseName);
            inheritHash->insert(className, listBaseName);
        }
    }
}

ClassFactory &ClassFactory::getInstance()
{
    static ClassFactory sLo_factory;
    return sLo_factory;
}

void *ClassFactory::CreateReflex(const QString &rootName, const QString &className)
{
    Metadata* metadata = ClassFactory::getInstance().GetMetadata(rootName);
    if (metadata != nullptr)
    {
        QHash<QString, ReflexObjectClass*>* reflexObjectClassHash = metadata->GetReflexObjects();
        QHash<QString, ReflexObjectClass*>::const_iterator it = reflexObjectClassHash->constBegin();
        QHash<QString, ReflexObjectClass*>::const_iterator itEnd = reflexObjectClassHash->constEnd();
        while (it != itEnd)
        {
            if (!it.key().compare(className))
            {
                return metadata->CreateReflex(it.key());
            }
            it++;
        }
    }
    return nullptr;
}

bool ClassFactory::IsSubclassOf(const QString &childClassName, const QString &baseClassName, const QString &rootName)
{
    Metadata* metadata = GetMetadata(rootName);
    if (metadata != nullptr)
    {
        QHash<QString, QList<QString>>* inheritHash = metadata->GetInheritHash();
        QHash<QString, QList<QString>>::iterator itor = inheritHash->find(childClassName);
        QHash<QString, QList<QString>>::iterator itorE = inheritHash->end();
        if (itor != itorE)
        {
            QList<QString> listName = inheritHash->operator[](childClassName);
            QList<QString>::iterator iter = std::find(listName.begin(), listName.end(), baseClassName);
            QList<QString>::iterator iterEnd = listName.end();
            if (iter != iterEnd)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

Metadata::Metadata(const QString &rootName) :
    m_dRootName(rootName),
    m_dObjectReflexs(),
    m_dInheritHash()
{
}

Metadata::~Metadata()
{
    QHash<QString, ReflexObjectClass*>::iterator itor = m_dObjectReflexs.begin();
    QHash<QString, ReflexObjectClass*>::iterator itorEnd = m_dObjectReflexs.end();
    while (itor != itorEnd)
    {
        if (itor.value() != nullptr)
        {
            delete itor.value();
            itor.value() = nullptr;
        }
        itor++;
    }
    m_dObjectReflexs.clear();
}
void* Metadata::CreateReflex(const QString &className)
{
    ReflexObject constructor = nullptr;
    if (m_dObjectReflexs.find(className) != m_dObjectReflexs.end())
        constructor = m_dObjectReflexs.find(className).value()->reflexObject;
    if (constructor == nullptr)
        return nullptr;
    //创建实例
    return (*constructor)();
}
