#include <QtTest>
#include <QSignalSpy>
#include "abstractrule.h"
// add necessary includes here

class TestBonus : public QObject
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
    model = AbstractRule::createGeneric();
}

TestBonus::~TestBonus()
{

}

void TestBonus::test_id()
{
    QVERIFY(model->id().isNull());
    model->setId(id1);
    QCOMPARE(model->id(), id1);
}

void TestBonus::test_name()
{
    QSignalSpy spy(model.data(), SIGNAL(s_name(QString)));
    QVERIFY(model->name() != name1);
    model->setName(name1);
    QCOMPARE(model->name(), name1);
    QCOMPARE(spy.count(), 1);
}

void TestBonus::test_description()
{
    QSignalSpy spy(model.data(), SIGNAL(s_description(QString)));
    QVERIFY(model->description() != description1);
    model->setDescription(description1);
    QCOMPARE(model->description(), description1);
    QCOMPARE(spy.count(), 1);
}

void TestBonus::test_copy_consttructor()
{
    QVERIFY(copy.isNull());
    copy = AbstractRule::createGeneric(*model);
    QCOMPARE(copy->name(), name1);
}

void TestBonus::test_equality()
{
    QCOMPARE(*model, *copy);
}

void TestBonus::test_inferior()
{
    copy->setName(name1+"1");
    QCOMPARE(*model < *copy, true);
}


QTEST_APPLESS_MAIN(TestBonus)

#include "tst_testbonus.moc"
