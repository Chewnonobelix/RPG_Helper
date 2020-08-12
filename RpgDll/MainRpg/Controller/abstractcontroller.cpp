#include "abstractcontroller.h"

InterfaceDataSave* AbstractController::m_db = nullptr;

AbstractController::AbstractController(QObject *parent) : QObject(parent)
{

}

InterfaceDataSave* AbstractController::db()
{
    return m_db;
}

void AbstractController::setDb(InterfaceDataSave * i)
{
    if(m_db)
        delete m_db;

    m_db = i;

    qDebug()<<m_db;
    try
    {
    if(m_db)
        m_db->init();
    }
    catch(QString error)
    {
        qDebug()<<"Init error"<<error;
    }
}
