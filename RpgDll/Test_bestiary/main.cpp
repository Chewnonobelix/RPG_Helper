#include <QApplication>
#include <QTest>
#include <QDebug>

#include "testobject.h"
#include "testweapon.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    int status = 0;

    //Tools unit test
    TestObject to;
    TestWeapon tw;
    
    status |= QTest::qExec(&to, argc, argv);
    status |= QTest::qExec(&tw, argc, argv);

    return status;
}
