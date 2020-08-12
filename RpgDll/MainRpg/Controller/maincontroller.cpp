#include "maincontroller.h"

MainController::MainController()
{
    setDb(new SqlDataBase);
}

MainController::~MainController()
{
    setDb();
}
