#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "Controller/maincontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    
    QGuiApplication app(argc, argv);
    MainController mc;


    return app.exec();
}
