#ifndef MAINRPG_GLOBAL_H
#define MAINRPG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MAINRPG_LIBRARY)
#  define MAINRPG_EXPORT Q_DECL_EXPORT
#else
#  define MAINRPG_EXPORT Q_DECL_IMPORT
#endif

#endif // MAINRPG_GLOBAL_H
