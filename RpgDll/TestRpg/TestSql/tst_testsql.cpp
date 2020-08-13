#include <QtTest>
#include "Controller/sqldatabase.h"

// add necessary includes here

class TestSql : public QObject
{
    Q_OBJECT
private:
    QSharedPointer<SqlDataBase> model;

public:
    TestSql();
    ~TestSql();

private slots:
    void initTestCase();
    void test_init();
    void test_addCreature();
    void cleanupTestCase();
};

TestSql::TestSql()
{

}

void TestSql::initTestCase()
{
    model.reset(new SqlDataBase);
    qDebug()<<QString(REQFILE)<<QFile::exists(QString(REQFILE));
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
    auto c = AbstractCreature::createGeneric();
    QCOMPARE(model->addCreature(c), true);
    QVERIFY(!c->id().isNull());
}

QTEST_APPLESS_MAIN(TestSql)

#include "tst_testsql.moc"
