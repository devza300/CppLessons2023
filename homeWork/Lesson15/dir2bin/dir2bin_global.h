#ifndef DIR2BIN_GLOBAL_H
#define DIR2BIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DIR2BIN_LIBRARY)
#  define DIR2BIN_EXPORT Q_DECL_EXPORT
#else
#  define DIR2BIN_EXPORT Q_DECL_IMPORT
#endif

/*!
 * \brief ObjectSize - размер поля, хранящего полный размер структуры
 */
typedef quint32 ObjectSize;

#endif // DIR2BIN_GLOBAL_H
