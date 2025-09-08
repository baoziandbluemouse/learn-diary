#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QApplication>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //这种代码块结束了就被回收的对话框算非模块对话框
    //只会一闪而过
    //QDialog w;
    //w.show();
    //模态对话框就是当该对话框弹出后会阻塞其他窗口的响应事件，必须先关闭该对话框，其他窗口才会继续响应事件。
    auto w = new QDialog();
    w->setWindowFlag(Qt::WindowStaysOnTopHint);//这个可以使对话框置顶
    w->setModal(true);
    w->show();

    //另一种方法,exec这个函数会阻塞其他界面响应事件。
    //QDialog w(this);
    //w.exec();


}

MainWindow::~MainWindow()
{
    delete ui;
}
