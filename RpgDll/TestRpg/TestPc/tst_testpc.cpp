#include <QtTest>
#include <QSignalSpy>
#include "abstractpc.h"
// add necessary includes here

class TestPc : public QObject
{
    Q_OBJECT
private:
    const int level1 = 2;
    const double current = 1.2;
    const double target = 2.4;
    const QString class1 = "c1";

public:
    TestPc();
    ~TestPc();

    QSharedPointer<AbstractPc> copy, model;

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
    model = AbstractPc::createGeneric();
}

TestPc::~TestPc()
{

}

void TestPc::test_level()
{
    QSignalSpy spy(model.data(), SIGNAL(s_level(int)));
    QVERIFY(model->level() != level1);
    model->setLevel(level1);
    QCOMPARE(model->level(), level1);
    QCOMPARE(spy.count(), 1);
}

void TestPc::test_currentXp()
{
    QSignalSpy spy(model.data(), SIGNAL(s_currentXp(double)));
    QVERIFY(model->currentXp() != current);
    model->setCurrentXp(current);
    QCOMPARE(model->currentXp(), current);
    QCOMPARE(spy.count(), 1);
}

void TestPc::test_targetXp()
{
    QSignalSpy spy(model.data(), SIGNAL(s_targetXp(double)));
    QVERIFY(model->targetXp() != target);
    model->setTargetXp(target);
    QCOMPARE(model->targetXp(), target);
    QCOMPARE(spy.count(), 1);
}

void TestPc::test_classes()
{
    QSignalSpy spy(model.data(), SIGNAL(s_classes(QString)));
    QVERIFY(model->classes() != class1);
    model->setClasses(class1);
    QCOMPARE(model->classes(), class1);
    QCOMPARE(spy.count(), 1);
}

void TestPc::test_copy()
{
    QVERIFY(copy.isNull());
    copy = AbstractPc::createGeneric(*model);
    QCOMPARE(copy->level(), level1);
}

void TestPc::test_equality()
{
    QCOMPARE(*model, *copy);
}

void TestPc::test_inferior()
{
    copy->setLevel(level1+1);
    QCOMPARE(*model < *copy, true);
}

QTEST_APPLESS_MAIN(TestPc)

#include "tst_testpc.moc"
