#ifndef RPGDLL_GLOBAL_H
#define RPGDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RPGDLL_LIBRARY)
#  define RPGDLL_EXPORT Q_DECL_EXPORT
#else
#  define RPGDLL_EXPORT Q_DECL_IMPORT
#endif

#endif // RPGDLL_GLOBAL_H
