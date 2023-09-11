#ifndef PERSONMAPPER_H
#define PERSONMAPPER_H

#include <QObject>
#include <QRunnable>
#include <QDateTime>
#include <QRandomGenerator>
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class PersonMapper : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit PersonMapper(QObject *parent = nullptr);

private:
    struct Person
    {
    public:
        long id;
        QString name; // 姓名
        long phone; // 电话
        float salary; // 薪水
        QString company; // 公司
        int ifSingle; // 是否单身
        int sex; // 性别
        QString address; // 住址
        QDateTime createTime;
        QString createUser;
    };

    QString names[9] = {"黄某人", "负债程序猿", "谭sir", "郭德纲", "蔡徐鸡", "蔡徐母鸡", "李狗蛋", "铁蛋", "赵铁柱"};
    QString addrs[10] = {"黄浦区", "徐汇区", "长宁区", "静安区", "普陀区", "虹口区", "杨浦区", "浦东新区", "闵行区", "宝山区"};
    QString companys[10] = {"京东", "腾讯", "百度", "小米", "米哈游", "网易", "字节跳动", "美团", "蚂蚁", "完美世界"};

protected:
    void run();

private:
    void insert(QList<Person> persons);

private:
    Person getPerson();
    QList<Person> getPersonList(int count);

    QSqlDatabase db;
};

#endif // PERSONMAPPER_H
