#ifndef GLOBALS_H
#define GLOBALS_H

#include "qtconfigmacros.h"
#include "qtypes.h"
#include <QTextStream>

QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE

extern QTextStream* g_logStream;
extern qint64 g_startTime;

#endif // GLOBALS_H
