#include "testweapon.h"

const QString damage1 = "1D10";
const QString damage2 = "2D10";

TestWeapon::TestWeapon()
{
    
}

TestWeapon::TestWeapon(const TestWeapon& tw): AbstractWeapon(tw)
{}

TestWeapon::~TestWeapon()
{}

void TestWeapon::initTestCase() {}
void TestWeapon::cleanupTestCase() {}

void TestWeapon::testSetDamage()
{
    QSignalSpy spy(this, SIGNAL(s_damage(QString)));
    setDamage(damage1);
    QCOMPARE(spy.count(), 1);
}

void TestWeapon::testDamage()
{
    QCOMPARE(damage(), damage1);
}

void TestWeapon::testCopy()
{
    copy = QSharedPointer<TestWeapon>::create(*this);
    QVERIFY2(!copy.isNull(), "Test copy");
}

void TestWeapon::testEquality()
{
    QCOMPARE(*this, *copy);   
}

void TestWeapon::testInferior()
{
    copy->setDamage(damage2);
    
    QCOMPARE(*this < *copy, true);
}
