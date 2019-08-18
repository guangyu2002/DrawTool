#include "sbfileiomanager.h"
#include "sbdocument.h"
#include "sbifileio.h"

#include <QLibrary>
#include <QDir>
#include <QCoreApplication>

SBFileIOManager &SBFileIOManager::getInstance()
{
    static SBFileIOManager instance;
    return instance;;
}

SBFileIOManager::~SBFileIOManager()
{
    int count = m_dFileIOs.count();
    for (int i = 0;i < count; ++i)
    {
        if (m_dFileIOs[i] != nullptr)
        {
            delete m_dFileIOs[i];
        }
        m_dFileIOs[i] = nullptr;
    }
    m_dFileIOs.clear();
}

QString SBFileIOManager::saveFile(QString &fileName, SBDocument *doc)
{
    QFileInfo fileInfo(fileName);
    QString suffix = fileInfo.suffix();
    SBIFileIO *fileIO = nullptr;
    int count = m_dFileIOs.count();
    for (int i = 0; i< count; ++i)
    {
        QString ass = m_dFileIOs[i]->fileType();
        if (!m_dFileIOs[i]->fileType().compare(suffix))
        {
            fileIO = m_dFileIOs[i];
            break;
        }
    }
    if (fileIO == nullptr)
    {
        return "Unable to find the specified IFileIO";
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        return "Failed to save file";
    }
    QByteArray buff;
    QString info = fileIO->exportFile(buff, doc);
    if (info.isEmpty())
    {
        file.write(buff);
        file.close();
        return "";
    }
    else
    {
        return info;
    }
}

SBFileIOManager::SBFileIOManager() :
    m_dFileIOs()
{
    typedef SBIFileIO* (*GetIFileIO)();
    QDir curDir(QCoreApplication::applicationDirPath());
    QStringList libFilters;
    libFilters << "*Translation*.dll" << "*Translation*.so" << "*Translation*.dylib";
    curDir.setNameFilters(libFilters);
    QStringList fileNameList = curDir.entryList(libFilters);
    int count = fileNameList.count();
    for (int i = 0; i < count; ++i)
    {
        QFileInfo fileInfo(fileNameList[i]);
        QString name = fileInfo.completeBaseName();
        QLibrary lib(name);
        if (lib.load())
        {
            GetIFileIO funGetIFileIO = (GetIFileIO)lib.resolve("getIFileIO");
            if (funGetIFileIO)
            {
                SBIFileIO *fileIO = funGetIFileIO();
                if (fileIO)
                {
                    m_dFileIOs.push_back(fileIO);
                }
            }
        }
    }
}
