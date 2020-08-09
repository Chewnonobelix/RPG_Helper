#ifndef ABSTRACTPC_H
#define ABSTRACTPC_H

#include <QObject>
#include "metadata.h"
#include "Bestiary_global.h"

class BESTIARY_EXPORT AbstractPc : public QObject, protected MetaData
{
    Q_OBJECT

    Q_PROPERTY(QStringList classes READ classes WRITE setClasses NOTIFY s_classes)
    Q_PROPERTY(int level READ level WRITE setLevel NOTIFY s_level)
    Q_PROPERTY(double curentXp READ currentXp WRITE setCurrentXp NOTIFY s_currentXp)
    Q_PROPERTY(double targetXp READ targetXp WRITE setTargetXp NOTIFY s_targetXp)

public:
    AbstractPc() = default;
    AbstractPc(const AbstractPc&);
    ~AbstractPc() = default;

    int level() const;
    void setLevel(int);
    double currentXp() const;
    void setCurrentXp(double);
    double targetXp() const;
    void setTargetXp(double);
    QStringList classes() const;
    void setClasses(QStringList);

    virtual void addXp(double) = 0;

    virtual bool operator ==(const AbstractPc&) const;
    virtual bool operator < (const AbstractPc&) const;
    AbstractPc& operator = (const AbstractPc&);

signals:
    void s_level(int);
    void s_currentXp(double);
    void s_targetXp(double);
    void s_classes(QStringList);
};

#endif // ABSTRACTPC_H
