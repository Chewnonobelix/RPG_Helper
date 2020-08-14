#ifndef ABSRACTBONUS_H
#define ABSRACTBONUS_H

#include <QObject>
#include <QUuid>
#include <QSet>
#include <QSharedPointer>
#include "Bestiary_global.h"
#include "metadata.h"
#include "designpattern.h"

class BESTIARY_EXPORT AbstractRule : public QObject, protected MetaData
{
    Q_OBJECT
    
	Q_PROPERTY(QUuid id READ id CONSTANT)
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY s_name)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY s_description)
    
public:
    AbstractRule();
    AbstractRule(const AbstractRule&);
    ~AbstractRule() = 0;
    
    static QSharedPointer<AbstractRule> createGeneric();
    static QSharedPointer<AbstractRule> createGeneric(const AbstractRule&);

    virtual AbstractRule& operator =(const AbstractRule&);
    virtual bool operator ==(const AbstractRule&) const;
    virtual bool operator <(const AbstractRule&) const;
    
	QUuid id() const;
	void setId(QUuid);
    QString name() const;
    void setName(QString);
    
    QString description() const;
    void setDescription(QString);
    
    Q_INVOKABLE virtual void setMetadata(QString , QString );
    Q_INVOKABLE virtual QString metaData(QString) const;
    Q_INVOKABLE virtual QStringList metadataList() const;

signals:
    void s_name(QString);
    void s_description(QString);
    void s_metadata(QString, QString);
};

typedef QSharedPointer<AbstractRule> RulePointer;
#endif // ABSRACTBONUS_H
