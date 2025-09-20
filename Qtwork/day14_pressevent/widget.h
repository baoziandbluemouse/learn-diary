#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QTimer>
#include <QTime>

//Qt中提供了两种方式实现定时器
//第一种是通过startTimer的方式启动定时器，该函数返回定时器的id，然后我们需要为实现定时器的类重写timerEvent。
//第二种是写个QTimer，并用信号连接一个槽函数，来显示时间，这个比较方便
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void timerEvent(QTimerEvent *event);
    void slot_update_led();

private:
    Ui::Widget *ui;
    int id1;
    int id2;
    int id3;
};
#endif // WIDGET_H
