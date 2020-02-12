#include <QApplication>
#include <QTest>
#include <QDebug>

#include "testobject.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    int status = 0;

    //Tools unit test
    TestObject to;
    
    status |= QTest::qExec(&to, argc, argv);


    return status;
}
