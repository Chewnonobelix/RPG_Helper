#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include <QObject>
#include <QTest>
#include <QSignalSpy>
#include "abstractobject.h"


class TestObject : public AbstractObject
{
    Q_OBJECT
public:
    explicit TestObject();
    TestObject(const TestObject&);
    ~TestObject();
    QSharedPointer<TestObject> copy;
    
signals:
    
private slots:
    void initTestCase();
    void cleanupTestCase();
    
    void testSetName();
    void testName();
    void testCopy();
    void testEquality();    
    void testInferior();    
};

#endif // TESTOBJECT_H
