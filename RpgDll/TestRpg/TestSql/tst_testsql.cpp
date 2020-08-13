#include <QtTest>
#include "Controller/sqldatabase.h"

// add necessary includes here

class TestSql : public QObject
{
    Q_OBJECT
private:
    QSharedPointer<SqlDataBase> model;
    CreaturePointer c1 = AbstractCreature::createGeneric(), c2 = AbstractCreature::createGeneric();
    RulePointer r1 = AbstractRule::createGeneric(), r2 = AbstractRule::createGeneric();
    ObjectPointer o1 = AbstractObject::createGeneric(), o2 = AbstractObject::createGeneric();
    WeaponPointer w1 = AbstractWeapon::createGeneric(), w2 = AbstractWeapon::createGeneric();

    const QString name = "name1";
    const QString description = "descrition1";
    const QString race = "race1";
    const QString damage = "race1";

public:
    TestSql();
    ~TestSql();

private slots:
    void initTestCase();
    void test_init();

    void test_addCreature();
    void test_selectAllCreature();
    void test_selectOneCreature();
    void test_updateCreature();
    void test_removeCreature();

    void test_addRule();
    void test_selectAllRule();
    void test_selectOneRule();
    void test_updateRule();
    void test_removeRule();

    void test_addObject();
    void test_selectAllObject();
    void test_selectOneObject();
    void test_updateObject();
    void test_removeObject();

    void test_addWeapon();
    void test_selectAllWeapon();
    void test_selectOneWeapon();
    void test_updateWeapon();
    void test_removeWeapon();


    void cleanupTestCase();
};

TestSql::TestSql()
{

}

void TestSql::initTestCase()
{
    model.reset(new SqlDataBase);
    qDebug()<<QString(REQFILE)<<QFile::exists(QString(REQFILE));
    c1->setName(name);
    c1->setRace(race);
    c1->setDescription(description);
    c2->setName(name);
    c2->setRace(race);
    c2->setDescription(description);

    r1->setName(name);
    r1->setDescription(description);
    r2->setName(name);
    r2->setDescription(description);

    o1->setName(name);
    o2->setName(name);

    w1->setDamage(damage);
    w2->setDamage(damage);
}

void TestSql::cleanupTestCase()
{
    model.clear();
    qDebug()<<QFile::remove("generic")<<QFile::exists("generic");
}

TestSql::~TestSql()
{
}

void TestSql::test_init()
{
    try
    {
        QCOMPARE(model->init(), true);
    }
    catch(QString error)
    {
        qDebug()<<error;
        QFAIL("Exeption");
    }
}

void TestSql::test_addCreature()
{
    QCOMPARE(model->addCreature(c1), true);
    QVERIFY(!c1->id().isNull());
    QCOMPARE(model->addCreature(c2), true);
}

void TestSql::test_selectAllCreature()
{
    QCOMPARE(model->selectCreature().size(), 2);
    QCOMPARE(model->selectCreature().contains(c1->id()), true);
    QCOMPARE(model->selectCreature().contains(c2->id()), true);
}

void TestSql::test_selectOneCreature()
{
    QCOMPARE(model->selectCreature({c1->id()}).size(), 1);
    QCOMPARE(model->selectCreature({c1->id()}).contains(c1->id()), true);
}

void TestSql::test_updateCreature()
{
    c2->setName(name+"1");
    QCOMPARE(model->updateCreature(c2), true);
    QCOMPARE(model->selectCreature({c2->id()}).first()->name(), name+"1");
}

void TestSql::test_removeCreature()
{
    QCOMPARE(model->removeCreature(c2), true);
    QCOMPARE(model->selectCreature().size(), 1);
    QCOMPARE(model->selectCreature().contains(c2->id()), false);
}

void TestSql::test_addRule()
{
    QCOMPARE(model->addRule(r1), true);
    QVERIFY(!r1->id().isNull());
    QCOMPARE(model->addRule(r2), true);
}

void TestSql::test_selectAllRule()
{
    QCOMPARE(model->selectRule().size(), 2);
    QCOMPARE(model->selectRule().contains(r1->id()), true);
    QCOMPARE(model->selectRule().contains(r2->id()), true);
}

void TestSql::test_selectOneRule()
{
    QCOMPARE(model->selectRule({r1->id()}).size(), 1);
    QCOMPARE(model->selectRule({r1->id()}).contains(r1->id()), true);
}

void TestSql::test_updateRule()
{
    r2->setName(name+"1");
    QCOMPARE(model->updateRule(r2), true);
    QCOMPARE(model->selectRule({r2->id()}).first()->name(), name+"1");
}

void TestSql::test_removeRule()
{
    QCOMPARE(model->removeRule(r2), true);
    QCOMPARE(model->selectRule().size(), 1);
    QCOMPARE(model->selectRule().contains(w2->id()), false);
}

void TestSql::test_addObject()
{
    QCOMPARE(model->addItem(o1), true);
    QVERIFY(!o1->id().isNull());
    QCOMPARE(model->addItem(o2), true);
}

void TestSql::test_selectAllObject()
{
    QCOMPARE(model->selectItem().size(), 2);
    QCOMPARE(model->selectItem().contains(o1->id()), true);
    QCOMPARE(model->selectItem().contains(o2->id()), true);
}

void TestSql::test_selectOneObject()
{
    QCOMPARE(model->selectItem({o1->id()}).size(), 1);
    QCOMPARE(model->selectItem({o1->id()}).contains(o1->id()), true);
}

void TestSql::test_updateObject()
{
    o2->setName(name+"1");
    QCOMPARE(model->updateItem(o2), true);
    QCOMPARE(model->selectItem({o2->id()}).first()->name(), name+"1");
}

void TestSql::test_removeObject()
{
    QCOMPARE(model->removeItem(o2), true);
    QCOMPARE(model->selectItem().size(), 1);
    QCOMPARE(model->selectItem().contains(o2->id()), false);
}

void TestSql::test_addWeapon()
{
    QCOMPARE(model->addWeapon(w1), true);
    QVERIFY(!w1->id().isNull());
    QCOMPARE(model->addWeapon(w2), true);
}

void TestSql::test_selectAllWeapon()
{
    QCOMPARE(model->selectWeapon().size(), 2);
    QCOMPARE(model->selectWeapon().contains(w1->id()), true);
    QCOMPARE(model->selectWeapon().contains(w2->id()), true);
}

void TestSql::test_selectOneWeapon()
{
    QCOMPARE(model->selectWeapon({w1->id()}).size(), 1);
    QCOMPARE(model->selectWeapon({w1->id()}).contains(w1->id()), true);
}

void TestSql::test_updateWeapon()
{
    w2->setDamage(name+"1");
    QCOMPARE(model->updateWeapon(w2), true);
    QCOMPARE(model->selectWeapon({w2->id()}).first()->damage(), name+"1");
}

void TestSql::test_removeWeapon()
{
    QCOMPARE(model->removeWeapon(w2), true);
    QCOMPARE(model->selectWeapon().size(), 1);
    QCOMPARE(model->selectWeapon().contains(w2->id()), false);
}

QTEST_APPLESS_MAIN(TestSql)

#include "tst_testsql.moc"
