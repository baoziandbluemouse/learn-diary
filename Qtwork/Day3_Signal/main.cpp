#include "mainwindow.h"

#include <QApplication>

//当我们需要一个界面通知另一个界面时，可以采用信号和槽机制。
//通过链接信号和槽，当一个界面发送信号时，链接该信号的槽会被响应，从而达到消息传递的目的。


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
