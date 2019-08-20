/**********************************************
 * 创建时间：2019.08.19
 * 作者：guangyu
 * 说明：自定义反射头文件
 * 修改记录：
***********************************************/

#ifndef SBREFLEX_H
#define SBREFLEX_H

#include "sbshape_global.h"

#include <QList>
#include <QHash>

class QString;

/****************************************************
 * 该宏定义实现了一个动态类的创建以及继续关系注册
 * 它创建了针对指定派生类的帮助类以及其静态全局对象
 * 构造函数:调用工厂类的注册函数，实现了类名和生成类实例函数的绑定
 * CreatObjFunc函数:生成一个类实例
 * 该宏利用全局对象初始化将反射派生类注册到ClassFactory实例中
 * 每个派生类想要能够进行反射，必须使用该宏修饰
 * 缺陷:需要反射的类要求必须有默认无参构造函数，带参数的构造函数(特别是参数是指针的情况)无法传入参数。
****************************************************/
#define REGISTERCLASS(className, baseName, rootName)\
class className##Helper\
{\
public:\
     className##Helper()\
     {\
        ClassFactory::getInstance().RegisterReflex(#className, #baseName, className##Helper::CreatObjFunc, #rootName);\
     }\
     static void* CreatObjFunc()\
     {\
        return new className;\
     }\
};\
static className##Helper className##helper;
/***************************************************
 * 该宏定义实现了一个抽象类的继承关系注册
 * 该宏与REGISTERCLASS不能同时修饰同一个类
***************************************************/
#define REGISTERCLASS_ABSTRACT(className, baseName, rootName)\
class className##Helper\
{\
public:\
     className##Helper()\
     {\
        ClassFactory::getInstance().RegisterReflex(#className, #baseName, NULL, #rootName);\
     }\
};\
static className##Helper className##helper;
/***********************************
 * 反射类型基类，所有需要反射的类都要派生与它
 * 根据具体需求，定于具体的虚方法给派生类调用
***********************************/
class Reflex
{
public:
    Reflex();
    virtual ~Reflex();
};

//定义一个返回值为void* 参数为null的回调函数指针
typedef void* (*ReflexObject)();

/************************************
 * 回调函数指针对象
************************************/
class ReflexObjectClass
{
public:
    explicit ReflexObjectClass(ReflexObject reflex)
        : reflexObject(reflex)
    {

    }
    ReflexObject reflexObject;
};
//自定义元数据，包含C++类的派生，实例构建指针等相关信息
class SBSHAPESHARED_EXPORT Metadata
{
public:
    Metadata(const QString &rootName);
    ~Metadata();

public:
    QString& GetRootName() { return m_dRootName; }
    QHash<QString, ReflexObjectClass*>* GetReflexObjects() { return &m_dObjectReflexs; }
    QHash<QString, QList<QString>>* GetInheritHash() { return &m_dInheritHash; }
    void* CreateReflex(const QString &className);//创建反射对象
private:
    //派生树最顶层基类名称
    QString m_dRootName;
    //缓存类名和生成类实例函数指针的Hash表
    QHash<QString, ReflexObjectClass*> m_dObjectReflexs;
    //缓存反射类的继承关系的Hash表
    QHash<QString, QList<QString>> m_dInheritHash;
};
//创建类实例工厂，单例模式
//存在隐患，如果存在多个系的派生树，并且存在相同名称的子节点时，会出现注册冲突
class SBSHAPESHARED_EXPORT ClassFactory
{
public:
    ~ClassFactory();
    //注册反射对象回调函数
    void RegisterReflex(const QString& className, const QString& baseName, ReflexObject reflexObject, const QString& rootName);
    Metadata* GetMetadata(const QString& rootName);
    static ClassFactory& getInstance();//获取工厂实例
    void *CreateReflex(const QString& rootName, const QString& className);
    bool IsSubclassOf(const QString& childClassName, const QString& baseClassName, const QString& rootName);
private:
    ClassFactory();
private:
    //注册的元数据集合
    QList<Metadata*> m_dMetadataList;

};

#endif // SBREFLEX_H
