/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：文件读写接口
 * 修改记录：
***********************************************/

#ifndef SBIFILEIO_H
#define SBIFILEIO_H

#include "sbshape_global.h"

#include <QString>

class SBDocument;
class SBSHAPESHARED_EXPORT SBIFileIO
{
public:
    SBIFileIO();
    virtual QString fileType() = 0;
    virtual QString exportFile(QByteArray &buff, SBDocument *doc) const = 0;
};

#endif // SBIFILEIO_H
