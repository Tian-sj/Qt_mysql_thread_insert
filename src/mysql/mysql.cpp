/*
 * @Author: Tian_sj
 * @Date: 2023-03-13 10:15:18
 * @LastEditors: Tian_sj tsj3911@163.com
 * @LastEditTime: 2023-05-10 10:33:08
 * @FilePath: /INVERTER_TEST_SYSTEM/src/mysql/mysql.cpp
 * @Description: 
 * Copyright (c) 2023 by 传麒科技(北京)股份有限公司.
 */
#include "mysql.h"

QSqlDatabase mysql::db = QSqlDatabase::addDatabase("QMYSQL");
QSqlQueryModel *mysql::model = new QSqlQueryModel();

mysql::mysql() {
}

void mysql::set_close_mysql()
{
    db.close();
    delete model;
    model = nullptr;
}

bool mysql::connect_mysql(const QString &Host, const int &Port, const QString &UserName, const QString &Password, const QString &DatabaseName) {
    db.setHostName(Host);
    db.setPort(Port);
    db.setUserName(UserName);
    db.setPassword(Password);
    db.setDatabaseName(DatabaseName);
    if (db.open())
        return true;
    else 
        return false;
}

bool mysql::is_query_table(const QString &sql) {
    QSqlQuery query(sql);
    if (query.size() > 0)
        return true;
    return false;
}

QSqlQuery mysql::query_value(const QString &sql)
{
    QSqlQuery query(sql);
    query.next();
    return query;
}

QSqlQuery mysql::query_all_value(const QString &sql)
{
    QSqlQuery query(sql);
    return query;
}

void mysql::update_value(const QString &sql)
{
    QSqlQuery query(sql);
//    qDebug() << sql;
//    qDebug() << query.lastError();
}
