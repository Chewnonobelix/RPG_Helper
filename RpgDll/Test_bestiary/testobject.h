#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include <QObject>

class TestObject : public QObject
{
    Q_OBJECT
public:
    explicit TestObject(QObject *parent = nullptr);
    
signals:
    
public slots:
    void initTestCase();
    void cleanupTestCase();

    void copy();
    void getName();
    void setName();
    void compare();
    void equality();    
};

#endif // TESTOBJECT_H
