#include <QApplication>
#include <QTest>
#include <QDebug>

#include "testobject.h"
#include "testweapon.h"
#include "testcreature.h"
#include "testbonus.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    int status = 0;
    
    qRegisterMetaType<ObjectPointer>("ObjectPointer");
    qRegisterMetaType<WeaponPointer>("WeaponPointer");
    qRegisterMetaType<CreaturePointer>("CreaturePointer");
    qRegisterMetaType<BonusPointer>("BonusPointer");
    //Tools unit test
    TestObject to;
    TestWeapon tw;
    TestBonus tb;
    TestCreature tc;
    
    
    status |= QTest::qExec(&to, argc, argv);
    status |= QTest::qExec(&tw, argc, argv);
    status |= QTest::qExec(&tb, argc, argv);
    status |= QTest::qExec(&tc, argc, argv);
    
    return status;
}
