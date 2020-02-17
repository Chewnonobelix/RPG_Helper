#include "testbonus.h"

const QString name1 = "Test name 1";
const QString name2 = "Test name 2";
const QString description1 = "Test description 1";
const QString description2 = "Test description 2";

using namespace DesignPattern;

TestBonus::TestBonus()
{
    
}

TestBonus::TestBonus(const TestBonus& tb): AbstractBonus(tb) {}

TestBonus::~TestBonus(){}

void TestBonus::initTestCase() {}
void TestBonus::cleanupTestCase() {}

void TestBonus::testSetName()
{
    QSignalSpy spy(this, SIGNAL(s_name(QString)));
    setName(name1);
    
    QCOMPARE(spy.count(), 1);
}
void TestBonus::testName() 
{
    QCOMPARE(name(), name1);
}

void TestBonus::testSetDescription() 
{
    QSignalSpy spy(this, SIGNAL(s_description(QString)));

    setDescription(description1);

    QCOMPARE(spy.count(), 1);    
}

void TestBonus::testDescription()
{
    QCOMPARE(description(), description1);
}

void TestBonus::testCopy()
{
    copy = factory<TestBonus>(*this);
    QVERIFY2(!copy.isNull(), "Test copy");
}

void TestBonus::testEquality()
{
    QCOMPARE(*this, *copy);    
}

void TestBonus::testInferior()
{
    copy->setName(name2);
    QCOMPARE(*this < *copy, true);
}
