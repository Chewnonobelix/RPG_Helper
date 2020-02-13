#ifndef TESTWEAPON_H
#define TESTWEAPON_H

#include <QTest>
#include <QSignalSpy>
#include "abstractweapon.h"
#include "testobject.h"
#include "designpattern.h"

class TestWeapon: public AbstractWeapon
{
    Q_OBJECT
    
public:
    TestWeapon();
    TestWeapon(const TestWeapon&);
    ~TestWeapon();
    QSharedPointer<TestWeapon> copy;
    
private slots:
    void initTestCase();
    void cleanupTestCase();
    
    void testSetDamage();
    void testDamage();
    void testCopy();
    void testEquality();    
    void testInferior();    
    void testDifferentType();
    
};

#endif // TESTWEAPON_H
