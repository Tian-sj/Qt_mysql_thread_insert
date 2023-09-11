#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <QObject>
#include <QThreadPool>

class PersonService : public QObject
{
    Q_OBJECT
public:
    explicit PersonService(QObject *parent = nullptr);

public slots:
    void insertList();

signals:
    void finishd();

};

#endif // PERSONSERVICE_H
