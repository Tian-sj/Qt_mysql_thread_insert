#include "personmapper.h"

#include <QDateTime>
#include <QThread>

PersonMapper::PersonMapper(QObject *parent)
    : QObject{parent}
{
    setAutoDelete(true);

}

void PersonMapper::run()
{
    db = QSqlDatabase::addDatabase("QMYSQL", QString::number((quint64)QThread::currentThreadId()));
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("test");
    db.open();
    for (int i = 0; i < 20; ++i) {
        insert(getPersonList(5000));
    }
    db.close();
}

void PersonMapper::insert(QList<Person> persons)
{
    QSqlQuery query(db);
    QString sql = "insert into person (name, phone, salary, company, if_single, sex, address, create_time, create_user) values";
    bool is = false;
    for (auto item : persons) {
        if (is) {
            sql += ",";
        }
        sql += QString("('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9')")
        .arg(item.name)
        .arg(item.phone)
        .arg(item.salary)
        .arg(item.company)
        .arg(item.ifSingle)
        .arg(item.sex)
        .arg(item.address)
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss"))
        .arg(item.createUser);
        is = true;
    }
    query.prepare(sql);
    query.exec();
}

PersonMapper::Person PersonMapper::getPerson()
{
    Person person;
    person.name = names[QRandomGenerator::global()->bounded(9)];
    person.phone = 18800000000L + QRandomGenerator::global()->bounded(88888888);
    person.salary = QRandomGenerator::global()->bounded(99999);
    person.company = companys[QRandomGenerator::global()->bounded(10)];
    person.ifSingle = QRandomGenerator::global()->bounded(2);
    person.sex = QRandomGenerator::global()->bounded(2);
    person.address = "上海市" + addrs[QRandomGenerator::global()->bounded(10)];
    person.createUser = names[QRandomGenerator::global()->bounded(9)];
    return person;
}

QList<PersonMapper::Person> PersonMapper::getPersonList(int count)
{
    QList<Person> persons;

    for (int i = 0; i < count; ++i) {
        persons.append(getPerson());
    }

    return persons;
}
