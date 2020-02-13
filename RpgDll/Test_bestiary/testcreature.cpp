#include "testcreature.h"

using namespace DesignPattern;

const QString name1 = "Test name1";
const QString name2 = "Test name2";
const QString race1 = "Test race1";
const QString race2 = "Test race2";
const QString description1 = "Test description1";
const QString description2 = "Test description2";

const QString characName = "C1";
constexpr double characValue = 1;

TestCreature::TestCreature()
{
    
}

TestCreature::TestCreature(const TestCreature& tc): AbstractCreature(tc)
{}

TestCreature::~TestCreature()
{}

void TestCreature::initTestCase() {}
void TestCreature::cleanupTestCase() {}

void TestCreature::testSetName() 
{
    QSignalSpy spy(this, SIGNAL(s_name(QString)));
    setName(name1);
    
    QCOMPARE(spy.count(), 1);
}

void TestCreature::testName()
{
    QCOMPARE(name(), name1);    
}

void TestCreature::testSetRace() 
{
    QSignalSpy spy(this, SIGNAL(s_race(QString)));
    setRace(race1);
    
    QCOMPARE(spy.count(), 1);
}

void TestCreature::testRace()
{
    QCOMPARE(race(), race1);    
}

void TestCreature::testSetDescription() 
{
    QSignalSpy spy(this, SIGNAL(s_description(QString)));
    setDescription(description1);
    
    QCOMPARE(spy.count(), 1);
}

void TestCreature::testDescription()
{
    QCOMPARE(description(), description1);    
}

void TestCreature::testSetCharacteristics() 
{
    QSignalSpy spy(this, SIGNAL(s_characteristics(QString, double)));
    setCharacteristics(characName, characValue);
    
    QCOMPARE(spy.count(), 1);
}

void TestCreature::testCharacteristics()
{
    QCOMPARE(characteristics(characName), characValue);
}

void TestCreature::testCharacteristicsList()
{
    QCOMPARE(characteristicsList(), QStringList(characName));
}

void TestCreature::testCopy() 
{
    copy = factory<TestCreature>(*this);
    QVERIFY2(!copy.isNull(), "Test copy");    
    copy->setName(name2);
}

void TestCreature::testEquality() 
{
    QCOMPARE(*this == *copy, false);
}

void TestCreature::testInferior()
{
    QCOMPARE(*this < *copy, true);
}

void TestCreature::testObject()
{
    QSKIP("TODO");
}

void TestCreature::testWeapons() 
{
    QSKIP("TODO");
}
