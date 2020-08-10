#include <QtTest>
#include <QSignalSpy>
#include "abstractcreature.h"
#include "itemimpl.h"
#include "ruleimpl.h"

// add necessary includes here

class TestCreature : public AbstractCreature
{
    Q_OBJECT
private:
	const QUuid id1 = QUuid::createUuid();
    const QString name1 = "name1";
    const QString description1 = "description1";
    const QString caracteriticName1 = "c1";
    const double caracteriticValue1 = 2.0;

    const QString itemName1 = "i1";
    const ObjectPointer itemValue1 = ItemImpl::create();

    const QString ruleName1 = "r1";
    const BonusPointer ruleValue1 = RuleImpl::create();

    QSharedPointer<AbstractCreature> copy;

public:
    TestCreature();
    ~TestCreature();

private slots:
    void test_id();
	void test_name();
    void test_description();
    void test_race();
    void test_caracteristic();
    void test_item();
    void test_rule();
    void test_copy_constructor();
    void test_equality();
    void test_inferior();

};

TestCreature::TestCreature()
{

}

TestCreature::~TestCreature()
{

}

void TestCreature::test_id()
{
	QVERIFY(id().isNull());
	setId(id1);
	QCOMPARE(id(), id1);
}


void TestCreature::test_name()
{
    QSignalSpy spy(this, SIGNAL(s_name(QString)));
    QVERIFY(this->name() != name1);
    setName(name1);
    QCOMPARE(this->name(), name1);
    QCOMPARE(spy.count(), 1);
}

void TestCreature::test_description()
{
    QSignalSpy spy(this, SIGNAL(s_description(QString)));
    QVERIFY(this->description() != name1);
    setDescription(name1);
    QCOMPARE(this->description(), name1);
    QCOMPARE(spy.count(), 1);
}

void TestCreature::test_race()
{
    QSignalSpy spy(this, SIGNAL(s_race(QString)));
    QVERIFY(this->race() != name1);
    setRace(name1);
    QCOMPARE(this->race(), name1);
    QCOMPARE(spy.count(), 1);
}

void TestCreature::test_caracteristic()
{
    QSignalSpy spy(this, SIGNAL(s_characteristics(QString, double)));
    QVERIFY(characteristicsList().isEmpty());
    setCharacteristics(caracteriticName1, caracteriticValue1);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(characteristicsList(), {caracteriticName1});
    QCOMPARE(characteristics(caracteriticName1), {caracteriticValue1});
}

void TestCreature::test_item()
{
    QSignalSpy spy(this, SIGNAL(s_object(QString, ObjectPointer)));
    QVERIFY(itemTypeList().isEmpty());
    setItem(itemName1, itemValue1);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(itemTypeList(), {itemName1});
    QCOMPARE(itemSet(itemName1), {itemValue1});
}

void TestCreature::test_rule()
{
    QSignalSpy spy(this, SIGNAL(s_rule(QString, BonusPointer)));
    QVERIFY(ruleTypeList().isEmpty());
    setRule(ruleName1, ruleValue1);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(ruleTypeList(), {ruleName1});
    QCOMPARE(ruleSet(ruleName1), {ruleValue1});
}

void TestCreature::test_copy_constructor()
{
    QVERIFY(copy.isNull());
    copy = QSharedPointer<TestCreature>::create(*this);
    QCOMPARE(copy->name(), name1);
}

void TestCreature::test_equality()
{
    QCOMPARE(*this, *copy);
}

void TestCreature::test_inferior()
{
    copy->setName(name1+"1");
    QCOMPARE(*this < *copy, true);
}


QTEST_APPLESS_MAIN(TestCreature)

#include "tst_testcreature.moc"
