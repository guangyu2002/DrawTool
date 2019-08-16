/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：文件读写接口
 * 修改记录：
***********************************************/

#ifndef SBIFILEIO_H
#define SBIFILEIO_H

#include <QString>

class SBIFileIO
{
public:
    SBIFileIO();

    virtual QString exportFile(const char *fileName) const = 0;
};

#endif // SBIFILEIO_H
