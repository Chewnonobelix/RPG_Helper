#include "maincontroller.h"

MainController::MainController()
{
    setDb(new SqlDataBase);
    qmlRegisterUncreatableType<AbstractObject>("Bestiary.Generic", 1, 0, "AbstractObject", "Abstract type");
    qmlRegisterUncreatableType<AbstractRule>("Bestiary.Generic", 1, 0, "AbstractRule", "Abstract type");
    qmlRegisterUncreatableType<AbstractCreature>("Bestiary.Generic", 1, 0, "AbstractCreature", "Abstract type");
    qmlRegisterUncreatableType<AbstractWeapon>("Bestiary.Generic", 1, 0, "AbstractWeapon", "Abstract type");

    m_engine.load(QUrl("qrc:/Main.qml"));
    auto root = m_engine.rootObjects().first();
}

MainController::~MainController()
{
    setDb();
}
