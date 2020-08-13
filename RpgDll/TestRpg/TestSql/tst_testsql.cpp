#include <QtTest>

// add necessary includes here

class TestSql : public QObject
{
    Q_OBJECT

public:
    TestSql();
    ~TestSql();

private slots:
    void test_case1();

};

TestSql::TestSql()
{
    qDebug()<<QString(REQFILE)<<QFile::exists(QString(REQFILE));
}

TestSql::~TestSql()
{

}

void TestSql::test_case1()
{

}

QTEST_APPLESS_MAIN(TestSql)

#include "tst_testsql.moc"
