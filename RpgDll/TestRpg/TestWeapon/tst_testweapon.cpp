#include <QtTest>
#include "abstractweapon.h"

// add necessary includes here

class TestWeapon : public QObject
{
    Q_OBJECT

private:
    const QString damage1 = "damage1";
    const QString name1 = "name1";
    QSharedPointer<AbstractWeapon> copy, model;


public:
    TestWeapon();
    ~TestWeapon();

private slots:
    void test_damage();
    void test_copy_consttructor();
    void test_equality();
    void test_inferior();
};

TestWeapon::TestWeapon()
{
    model = AbstractWeapon::createGeneric();
    model->setName(name1);
}

TestWeapon::~TestWeapon()
{

}

void TestWeapon::test_damage()
{
    QSignalSpy spy(model.data(), SIGNAL(s_damage(QString)));
    QVERIFY(model->damage() != damage1);
    model->setDamage(damage1);
    QCOMPARE(model->damage(), damage1);
    QCOMPARE(spy.count(), 1);
}

void TestWeapon::test_copy_consttructor()
{
    QVERIFY(copy.isNull());
    copy = QSharedPointer<AbstractWeapon>::create(*model);
    QCOMPARE(copy->name(), name1);
}

void TestWeapon::test_equality()
{
    QCOMPARE(*model, *copy);
}

void TestWeapon::test_inferior()
{
    copy->setDamage(damage1+"1");
    QCOMPARE(*model < *copy, true);
}

QTEST_APPLESS_MAIN(TestWeapon)

#include "tst_testweapon.moc"
