#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "Gamemaster/Controller/controllermainmaster.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    
    QGuiApplication app(argc, argv);

    ControllerMainMaster master;

    for(int i = 0; i < 50; i++)
        master.exec();

    return app.exec();
}
