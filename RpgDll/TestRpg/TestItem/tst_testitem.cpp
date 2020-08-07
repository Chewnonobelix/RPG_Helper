#include <QtTest>
#include "abstractobject.h"

// add necessary includes here

class TestItem : public AbstractObject
{
    Q_OBJECT
private:
    const QString name1 = "name1";
    QSharedPointer<AbstractObject> copy;

public:
    TestItem();
    ~TestItem();

private slots:
    void test_name();
    void test_copy_consttructor();
    void test_equality();
    void test_inferior();
};

TestItem::TestItem()
{

}

TestItem::~TestItem()
{

}

void TestItem::test_name()
{
    QSignalSpy spy(this, SIGNAL(s_name(QString)));
    QVERIFY(this->name() != name1);
    setName(name1);
    QCOMPARE(this->name(), name1);
    QCOMPARE(spy.count(), 1);
}

void TestItem::test_copy_consttructor()
{
    QVERIFY(copy.isNull());
    copy = QSharedPointer<TestItem>::create(*this);
    QCOMPARE(copy->name(), name1);
}

void TestItem::test_equality()
{
    QCOMPARE(*this, *copy);
}

void TestItem::test_inferior()
{
    copy->setName(name1+"1");
    QCOMPARE(*this < *copy, true);
}


QTEST_APPLESS_MAIN(TestItem)

#include "tst_testitem.moc"
