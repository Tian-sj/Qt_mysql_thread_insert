#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <chrono>
#include <QTimer>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btn_start_clicked();

    void on_timer();

    void on_finished();

signals:
    void emit_start();

private:
    Ui::Widget *ui;

    QThread *the_thread;
    QTimer* timer;
    int start_time;
};
#endif // WIDGET_H
