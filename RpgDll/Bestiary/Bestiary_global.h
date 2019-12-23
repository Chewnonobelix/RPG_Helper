#ifndef BESTIARY_GLOBAL_H
#define BESTIARY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BESTIARY_LIBRARY)
#  define BESTIARY_EXPORT Q_DECL_EXPORT
#else
#  define BESTIARY_EXPORT Q_DECL_IMPORT
#endif

#endif // BESTIARY_GLOBAL_H
