/*
 * @Author: Tian_sj
 * @Date: 2023-03-11 10:42:14
 * @LastEditors: Tian_sj tsj3911@163.com
 * @LastEditTime: 2023-05-10 10:33:12
 * @FilePath: /INVERTER_TEST_SYSTEM/src/mysql/mysql.h
 * @Description: 
 * Copyright (c) 2023 by 传麒科技(北京)股份有限公司.
 */
#ifndef MYSQL_H
#define MYSQL_H

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDebug>

class mysql
{
public:
    static QSqlDatabase db;
    static QSqlQueryModel *model;

public:
    mysql(/* args */);

    static void set_close_mysql();

public:
    // 连接数据库
    static bool connect_mysql(const QString &Host, const int &Port, const QString &UserName, const QString &Password, const QString &DatabaseName);

    // 查询判断
    static bool is_query_table(const QString &);

    // 返回查询单一结果
    static QSqlQuery query_value(const QString &);

    // 返回全部结果
    static QSqlQuery query_all_value(const QString &);

    // 修改数据
    static void update_value(const QString &);
};

#endif // MYSQL_H
