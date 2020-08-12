#include <QtTest>
#include <QSignalSpy>
#include "abstractcreature.h"
#include "itemimpl.h"
#include "ruleimpl.h"

// add necessary includes here

class TestCreature : public QObject
{
    Q_OBJECT
private:
	const QUuid id1 = QUuid::createUuid();
    const QString name1 = "name1";
    const QString description1 = "description1";
    const QString caracteriticName1 = "c1";
    const double caracteriticValue1 = 2.0;

    const QString itemName1 = "i1";
    const ObjectPointer itemValue1 = AbstractObject::createGeneric();

    const QString ruleName1 = "r1";
    const RulePointer ruleValue1 = AbstractRule::createGeneric();

    const QString class1 = "cl1";
    const PcPointer classValue1 = AbstractPc::createGeneric();

    QSharedPointer<AbstractCreature> copy, model;

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
    void test_class();
    void test_copy_constructor();
    void test_equality();
    void test_inferior();

};

TestCreature::TestCreature()
{
    model = AbstractCreature::createGeneric();
}

TestCreature::~TestCreature()
{

}

void TestCreature::test_id()
{
    QVERIFY(model->id().isNull());
    model->setId(id1);
    QCOMPARE(model->id(), id1);
}


void TestCreature::test_name()
{
    QSignalSpy spy(model.data(), SIGNAL(s_name(QString)));
    QVERIFY(model->name() != name1);
    model->setName(name1);
    QCOMPARE(model->name(), name1);
    QCOMPARE(spy.count(), 1);
}

void TestCreature::test_description()
{
    QSignalSpy spy(model.data(), SIGNAL(s_description(QString)));
    QVERIFY(model->description() != name1);
    model->setDescription(name1);
    QCOMPARE(model->description(), name1);
    QCOMPARE(spy.count(), 1);
}

void TestCreature::test_race()
{
    QSignalSpy spy(model.data(), SIGNAL(s_race(QString)));
    QVERIFY(model->race() != name1);
    model->setRace(name1);
    QCOMPARE(model->race(), name1);
    QCOMPARE(spy.count(), 1);
}

void TestCreature::test_caracteristic()
{
    QSignalSpy spy(model.data(), SIGNAL(s_characteristics(QString, double)));
    QVERIFY(model->characteristicsList().isEmpty());
    model->setCharacteristics(caracteriticName1, caracteriticValue1);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(model->characteristicsList(), {caracteriticName1});
    QCOMPARE(model->characteristics(caracteriticName1), {caracteriticValue1});
}

void TestCreature::test_item()
{
    QSignalSpy spy(model.data(), SIGNAL(s_object(QString, ObjectPointer)));
    QVERIFY(model->itemTypeList().isEmpty());
    model->setItem(itemName1, itemValue1);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(model->itemTypeList(), {itemName1});
    QCOMPARE(model->itemSet(itemName1), {itemValue1});
}

void TestCreature::test_rule()
{
    QSignalSpy spy(model.data(), SIGNAL(s_rule(QString, RulePointer)));
    QVERIFY(model->ruleTypeList().isEmpty());
    model->setRule(ruleName1, ruleValue1);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(model->ruleTypeList(), {ruleName1});
    QCOMPARE(model->ruleSet(ruleName1), {ruleValue1});
}

void TestCreature::test_class()
{
    QSignalSpy spy(model.data(), SIGNAL(s_classe(QString,PcPointer)));
    QVERIFY(model->classesList().isEmpty());
    model->setClasse(class1, classValue1);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(model->classesList(), {class1});
    QCOMPARE(model->classe(class1), classValue1);
}

void TestCreature::test_copy_constructor()
{
    QVERIFY(copy.isNull());
    copy = AbstractCreature::createGeneric(*model);
    QCOMPARE(copy->name(), name1);
}

void TestCreature::test_equality()
{
    QCOMPARE(*model, *copy);
}

void TestCreature::test_inferior()
{
    copy->setName(name1+"1");
    QCOMPARE(*model < *copy, true);
}


QTEST_APPLESS_MAIN(TestCreature)

#include "tst_testcreature.moc"
