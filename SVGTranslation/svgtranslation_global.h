/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：SVG模块导出类宏定义
 * 修改记录：
***********************************************/

#ifndef SVGTRANSLATION_GLOBAL_H
#define SVGTRANSLATION_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SVGTRANSLATION_LIBRARY)
#  define SVGTRANSLATIONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SVGTRANSLATIONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SVGTRANSLATION_GLOBAL_H
