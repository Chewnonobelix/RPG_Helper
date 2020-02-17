#ifndef TESTBONUS_H
#define TESTBONUS_H

#include <QTest>
#include <QSignalSpy>
#include "abstractbonus.h"
#include "designpattern.h"

class TestBonus: public AbstractBonus
{
    Q_OBJECT
    
public:
    TestBonus();
    TestBonus(const TestBonus&);
    ~TestBonus();

    QSharedPointer<AbstractBonus> copy;
    
private slots:
    void initTestCase();
    void cleanupTestCase();
    
    void testSetName();
    void testName();
    void testSetDescription();
    void testDescription();
    void testCopy();
    void testEquality();
    void testInferior();
};

#endif // TESTBONUS_H
