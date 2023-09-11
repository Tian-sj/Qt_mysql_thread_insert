#include "widget.h"
#include "./ui_widget.h"

#include "personservice.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    the_thread = new QThread;
}

Widget::~Widget()
{
    the_thread->deleteLater();

    delete ui;
}


void Widget::on_btn_start_clicked()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL", QString::number((quint64)QThread::currentThreadId()));
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("test");
    if (!db.open()) {
        QString msg = "数据库连接失败:" + db.lastError().text();
        QMessageBox::information(nullptr, "警告", msg);
        return;
    }
    db.close();

    ui->btn_start->setEnabled(false);
    timer = new QTimer;
    timer->setInterval(1);
    connect(timer, &QTimer::timeout, this, &Widget::on_timer);

    PersonService* test = new PersonService;
    test->moveToThread(the_thread);
    connect(test, &PersonService::finishd, this, &Widget::on_finished);
    connect(this, &Widget::emit_start, test, &PersonService::insertList);
    start_time = 0;
    the_thread->start();
    timer->start();
    emit emit_start();
}

void Widget::on_timer()
{
    ui->time->display(QString("%1").arg(++start_time));
}

void Widget::on_finished()
{
    timer->stop();

    delete timer;
    start_time = 0;
}

