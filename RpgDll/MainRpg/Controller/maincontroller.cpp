#include "maincontroller.h"

MainController::MainController()
{
    setDb(new SqlDataBase);
    qmlRegisterUncreatableType<AbstractObject>("Bestiary.Generic", 1, 0, "AbstractObject", "Abstract type");

    m_engine.load(QUrl("qrc:/Main.qml"));
    auto root = m_engine.rootObjects().first();
}

MainController::~MainController()
{
    setDb();
}
