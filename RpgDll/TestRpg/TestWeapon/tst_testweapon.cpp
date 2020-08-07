#include <QtTest>
#include "abstractweapon.h"

// add necessary includes here

class TestWeapon : public AbstractWeapon
{
    Q_OBJECT

private:
    const QString damage1 = "damage1";
    const QString name1 = "name1";
    QSharedPointer<AbstractWeapon> copy;


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
    setName(name1);
}

TestWeapon::~TestWeapon()
{

}

void TestWeapon::test_damage()
{
    QSignalSpy spy(this, SIGNAL(s_damage(QString)));
    QVERIFY(this->damage() != damage1);
    setDamage(damage1);
    QCOMPARE(this->damage(), damage1);
    QCOMPARE(spy.count(), 1);
}

void TestWeapon::test_copy_consttructor()
{
    QVERIFY(copy.isNull());
    copy = QSharedPointer<TestWeapon>::create(*this);
    QCOMPARE(copy->name(), name1);
}

void TestWeapon::test_equality()
{
    QCOMPARE(*this, *copy);
}

void TestWeapon::test_inferior()
{
    copy->setName(name1+"1");
    QCOMPARE(*this < *copy, true);
}

QTEST_APPLESS_MAIN(TestWeapon)

#include "tst_testweapon.moc"
