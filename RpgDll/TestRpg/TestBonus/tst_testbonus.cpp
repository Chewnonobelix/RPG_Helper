#include <QtTest>
#include <QSignalSpy>
#include "abstractrule.h"
// add necessary includes here

class TestBonus : public AbstractBonus
{
    Q_OBJECT
private:
	const QUuid id1 = QUuid::createUuid();
    const QString name1 = "name1";
    const QString description1 = "description1";
    QSharedPointer<AbstractRule> model, copy;

public:
    TestBonus();
    ~TestBonus();

private slots:
    void test_id();
    void test_name();
    void test_description();
    void test_copy_consttructor();
    void test_equality();
    void test_inferior();
};

TestBonus::TestBonus()
{

}

TestBonus::~TestBonus()
{

}

void TestBonus::test_id()
{
	QVERIFY(id().isNull());
	setId(id1);
	QCOMPARE(id(), id1);
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

void TestBonus::test_copy_consttructor()
{
    QVERIFY(copy.isNull());
    copy = QSharedPointer<TestBonus>::create(*this);
    QCOMPARE(copy->name(), name1);
}

void TestBonus::test_equality()
{
    QCOMPARE(*this, *copy);
}

void TestBonus::test_inferior()
{
    copy->setName(name1+"1");
    QCOMPARE(*this < *copy, true);
}


QTEST_APPLESS_MAIN(TestBonus)

#include "tst_testbonus.moc"
