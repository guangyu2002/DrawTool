#include "sbfileiomanager.h"
#include "sbdocument.h"

SBFileIOManager &SBFileIOManager::getInstance()
{
    static SBFileIOManager instance;
    return instance;;
}

QString SBFileIOManager::saveFile(QString &fileName, SBDocument *doc)
{
    return "1234";
}
