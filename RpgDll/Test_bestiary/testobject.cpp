#include "testobject.h"

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
    copy = QSharedPointer<TestObject>::create(*this);
    QVERIFY2(!copy.isNull(), "Test copy");
}

void TestObject::testName() 
{
    QVERIFY2(name() == name1, "Test getter");
}

void TestObject::testSetName() 
{
    setName(name1);
    QVERIFY(true);
}

void TestObject::testEquality() 
{
    QVERIFY2(*this == *copy, "Test equality");
}

void TestObject::testInferior() 
{
    (*copy).setName(name2);
    QVERIFY2(*this < * copy, "Test inferior");
}    
