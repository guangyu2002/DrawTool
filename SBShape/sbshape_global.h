#ifndef SBSHAPE_GLOBAL_H
#define SBSHAPE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SBSHAPE_LIBRARY)
#  define SBSHAPESHARED_EXPORT Q_DECL_EXPORT
#else
#  define SBSHAPESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SBSHAPE_GLOBAL_H
