#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

#include "interfacedatasave.h"

class AbstractController : public QObject
{
    Q_OBJECT
private:
    static InterfaceDataSave* m_db;

public:
    explicit AbstractController(QObject *parent = nullptr);
    static InterfaceDataSave* db();
    static void setDb(InterfaceDataSave* = nullptr);

signals:

};

#endif // ABSTRACTCONTROLLER_H
