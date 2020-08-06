#include <QtTest>
#include <QSignalSpy>
#include "abstractbonus.h"
// add necessary includes here

class TestBonus : public AbstractBonus
{
    Q_OBJECT
private:
    const QString name1 = "name1";
    const QString description1 = "description1";

public:
    TestBonus();
    ~TestBonus();

private slots:
    void test_name();
    void test_description();
};

TestBonus::TestBonus()
{

}

TestBonus::~TestBonus()
{

}

void TestBonus::test_name()
{
    QSignalSpy spy(this, SIGNAL(s_name(QString)));
    QVERIFY(this->name() != name1);
    setName(name1);
    QCOMPARE(this->name(), name1);
    QCOMPARE(spy.count(), 1);
}

void TestBonus::test_description()
{
    QSignalSpy spy(this, SIGNAL(s_description(QString)));
    QVERIFY(this->description() != description1);
    setDescription(description1);
    QCOMPARE(this->description(), description1);
    QCOMPARE(spy.count(), 1);
}

QTEST_APPLESS_MAIN(TestBonus)

#include "tst_testbonus.moc"
