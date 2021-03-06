#ifndef TESTCREATURE_H
#define TESTCREATURE_H

#include <QSignalSpy>
#include <QTest>

#include "abstractcreature.h"
#include "designpattern.h"
#include "testobject.h"

class TestCreature: public AbstractCreature
{
    Q_OBJECT
    
private:
    QSharedPointer<TestCreature> copy;
    
public:
    explicit TestCreature();
    TestCreature(const TestCreature&);
    ~TestCreature();
    QSet<ObjectPointer> cso;
    
private slots:
    void initTestCase();
    void cleanupTestCase();
    
    void testSetName();
    void testName();
    void testSetRace();
    void testRace();
    void testSetDescription();
    void testDescription();
    void testSetCharacteristics();
    void testCharacteristics();
    void testCharacteristicsList();
    void testCopy();
    void testEquality();
    void testInferior();

    void testSetItem();
    void testItem();
    void testItemList();
};

#endif // TESTCREATURE_H
