#include <QtTest>
#include "Controller/sqldatabase.h"

// add necessary includes here

class TestSql : public QObject
{
    Q_OBJECT
private:
    QSharedPointer<SqlDataBase> model;
    CreaturePointer c1 = AbstractCreature::createGeneric(), c2 = AbstractCreature::createGeneric();
    const QString name = "name1";
    const QString description = "descrition1";
    const QString race = "race1";

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

QTEST_APPLESS_MAIN(TestSql)

#include "tst_testsql.moc"
