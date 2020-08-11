#ifndef ABSTRACTPC_H
#define ABSTRACTPC_H

#include <QObject>
#include <QSharedPointer>
#include "metadata.h"
#include "designpattern.h"
#include "Bestiary_global.h"

class BESTIARY_EXPORT AbstractPc : public QObject, protected MetaData
{
    Q_OBJECT

    Q_PROPERTY(QString classes READ classes WRITE setClasses NOTIFY s_classes)
    Q_PROPERTY(int level READ level WRITE setLevel NOTIFY s_level)
    Q_PROPERTY(double curentXp READ currentXp WRITE setCurrentXp NOTIFY s_currentXp)
    Q_PROPERTY(double targetXp READ targetXp WRITE setTargetXp NOTIFY s_targetXp)

public:
    AbstractPc();
    AbstractPc(const AbstractPc&);
    ~AbstractPc() = default;

    int level() const;
    void setLevel(int);
    double currentXp() const;
    void setCurrentXp(double);
    double targetXp() const;
    void setTargetXp(double);
    QString classes() const;
    void setClasses(QString);

    virtual void addXp(double) = 0;

    static QSharedPointer<AbstractPc> createGeneric();
    static QSharedPointer<AbstractPc> createGeneric(const AbstractPc&);

    virtual bool operator ==(const AbstractPc&) const;
    virtual bool operator < (const AbstractPc&) const;
    AbstractPc& operator = (const AbstractPc&);

signals:
    void s_level(int);
    void s_currentXp(double);
    void s_targetXp(double);
    void s_classes(QString);
};

typedef QSharedPointer<AbstractPc> PcPointer;

#endif // ABSTRACTPC_H
