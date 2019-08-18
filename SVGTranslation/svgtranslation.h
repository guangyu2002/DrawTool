/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：svg转换类
 * 修改记录：
***********************************************/

#ifndef SVGTRANSLATION_H
#define SVGTRANSLATION_H

#include "svgtranslation_global.h"


#include "sbifileio.h"

class SVGTRANSLATIONSHARED_EXPORT SVGFileIO : public SBIFileIO
{

public:
    SVGFileIO();

    // SBIFileIO interface
public:
    QString exportFile(const char *fileName, const SBDocument *doc) const Q_DECL_OVERRIDE;
    inline QString fileType() Q_DECL_OVERRIDE { return "svg"; }
};

#endif // SVGTRANSLATION_H
