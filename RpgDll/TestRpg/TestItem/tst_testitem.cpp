#include <QtTest>
#include "abstractobject.h"

// add necessary includes here

class TestItem : public QObject
{
    Q_OBJECT
private:
    const QString name1 = "name1";
	const QUuid id1 = QUuid::createUuid();
    QSharedPointer<AbstractObject> copy, model;

public:
    TestItem();
    ~TestItem();

private slots:
    void test_id();
    void test_name();
    void test_copy_consttructor();
    void test_equality();
    void test_inferior();
};

TestItem::TestItem()
{
    model = AbstractObject::createGeneric();
}

TestItem::~TestItem()
{

}

void TestItem::test_id()
{
    QVERIFY(model->id().isNull());
    model->setId(id1);
    QCOMPARE(model->id(), id1);
}

void TestItem::test_name()
{
    QSignalSpy spy(model.data(), SIGNAL(s_name(QString)));
    QVERIFY(model->name() != name1);
    model->setName(name1);
    QCOMPARE(model->name(), name1);
    QCOMPARE(spy.count(), 1);
}

void TestItem::test_copy_consttructor()
{
    QVERIFY(copy.isNull());
    copy = AbstractObject::createGeneric(*model);
    QCOMPARE(copy->name(), name1);
}

void TestItem::test_equality()
{
    QCOMPARE(*model, *copy);
}

void TestItem::test_inferior()
{
    copy->setName(name1+"1");
    QCOMPARE(*model < *copy, true);
}


QTEST_APPLESS_MAIN(TestItem)

#include "tst_testitem.moc"
