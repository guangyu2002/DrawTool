/**********************************************
 * 创建时间：2019.08.18
 * 作者：guangyu
 * 说明：文件读写接口,单例模式
 * 修改记录：
***********************************************/

#ifndef SBFILEIOMANAGER_H
#define SBFILEIOMANAGER_H

#include "sbshape_global.h"

#include <QString>

class SBDocument;
class SBSHAPESHARED_EXPORT SBFileIOManager
{
public:
    static SBFileIOManager &getInstance();

    QString saveFile(QString &fileName, SBDocument *doc);

private:
    SBFileIOManager(){}
    SBFileIOManager(const SBFileIOManager&) = delete;
    SBFileIOManager &operator=(const SBFileIOManager&) = delete;
};

#endif // SBFILEIOMANAGER_H
