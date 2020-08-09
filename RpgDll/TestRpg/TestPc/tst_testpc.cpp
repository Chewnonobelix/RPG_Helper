#include <QtTest>
#include <QSignalSpy>
#include "abstractpc.h"
// add necessary includes here

class TestPc : public AbstractPc
{
    Q_OBJECT
private:
    const int level1 = 2;
    const double current = 1.2;
    const double target = 2.4;
    const QStringList class1 = {"c1"};

public:
    TestPc();
    ~TestPc();

    void addXp(double);
    QSharedPointer<AbstractPc> copy;
private slots:
    void test_level();
    void test_currentXp();
    void test_targetXp();
    void test_classes();
    void test_copy();
    void test_equality();
    void test_inferior();
};

TestPc::TestPc()
{

}

TestPc::~TestPc()
{

}

void TestPc::addXp(double)
{}

void TestPc::test_level()
{
    QSignalSpy spy(this, SIGNAL(s_level(int)));
    QVERIFY(this->level() != level1);
    setLevel(level1);
    QCOMPARE(this->level(), level1);
    QCOMPARE(spy.count(), 1);
}

void TestPc::test_currentXp()
{
    QSignalSpy spy(this, SIGNAL(s_currentXp(double)));
    QVERIFY(this->currentXp() != current);
    setCurrentXp(current);
    QCOMPARE(this->currentXp(), current);
    QCOMPARE(spy.count(), 1);
}

void TestPc::test_targetXp()
{
    QSignalSpy spy(this, SIGNAL(s_targetXp(double)));
    QVERIFY(this->targetXp() != target);
    setTargetXp(target);
    QCOMPARE(this->targetXp(), target);
    QCOMPARE(spy.count(), 1);
}

void TestPc::test_classes()
{
    QSignalSpy spy(this, SIGNAL(s_classes(QStringList)));
    QVERIFY(this->classes() != class1);
    setClasses(class1);
    QCOMPARE(this->classes(), class1);
    QCOMPARE(spy.count(), 1);
}

void TestPc::test_copy()
{
    QVERIFY(copy.isNull());
    copy = QSharedPointer<TestPc>::create(*this);
    QCOMPARE(copy->level(), level1);
}

void TestPc::test_equality()
{
    QCOMPARE(*this, *copy);
}

void TestPc::test_inferior()
{
    copy->setLevel(level1+1);
    QCOMPARE(*this < *copy, true);
}

QTEST_APPLESS_MAIN(TestPc)

#include "tst_testpc.moc"
