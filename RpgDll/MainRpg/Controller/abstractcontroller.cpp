#include "abstractcontroller.h"

InterfaceDataSave* AbstractController::m_db = nullptr;

AbstractController::AbstractController(QObject *parent) : QObject(parent)
{

}

InterfaceDataSave* AbstractController::db()
{
    return m_db;
}
