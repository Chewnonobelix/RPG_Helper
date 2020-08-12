#include "maincontroller.h"

MainController::MainController()
{
    qDebug()<<"Pouet";
    setDb(new SqlDataBase);
}

MainController::~MainController()
{
    qDebug()<<"Choucroute";
    setDb();
}
