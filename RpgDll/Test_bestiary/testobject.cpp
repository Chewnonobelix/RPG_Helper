#include "testobject.h"

using namespace DesignPattern;

const QString name1 = "Test Object 1";
const QString name2 = "Test Object 2";

TestObject::TestObject() : AbstractObject()
{
    
}

TestObject::TestObject(const TestObject& to) : AbstractObject(to)
{
    
}

TestObject::~TestObject() {}

void TestObject::initTestCase() {}
void TestObject::cleanupTestCase() {}

void TestObject::testCopy() 
{
    copy = factory<TestObject>(*this);
    QVERIFY2(!copy.isNull(), "Test copy");
}

void TestObject::testName() 
{
    QCOMPARE(name(), name1);
}

void TestObject::testSetName() 
{
    QSignalSpy spy(this, SIGNAL(s_name(QString)));
    
    setName(name1);
    QCOMPARE(spy.count(), 1);
}

void TestObject::testEquality() 
{
    QCOMPARE(*this, *copy);
}

void TestObject::testInferior() 
{
    (*copy).setName(name2);
    QVERIFY2(*this < * copy, "Test inferior");
}    
