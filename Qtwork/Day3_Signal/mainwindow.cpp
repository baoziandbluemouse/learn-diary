#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDialog>

//实现这样一个demo，程序启动后弹出主界面，点击主界面的按钮弹出子窗口，隐藏主界面，点击子窗口界面的按钮，隐藏子界面，显示主窗口。

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _child_dialog = new ChildDialog(this);
    //链接函数，将信号和槽函数进行链接，达成对这个按钮做点击操作就会触发槽函数
    //qt4 方式链接信号和槽函数,并不好
    //slot和signal只是宏转换，字符串定义不能检测编程错误
    //比如你在参数那里填点别的，导致进入不到我们想要的槽函数，这就链接不到了
    //connect(ui->showChildButton,SIGNAL(clicked(bool)),this,SLOT(showChildDialog()));
    //推荐的qt5方式,不需要传递函数参数，就不会出现qt4的错误
    connect(ui->showChildButton,&QPushButton::clicked,this,&MainWindow::showChildDialog);
    connect(_child_dialog,&ChildDialog::showMainSig,this,&MainWindow::showMainDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(_child_dialog){
        delete  _child_dialog;
        _child_dialog = nullptr;
    }
}

void MainWindow::showChildDialog()
{
    //点击按钮后，生成一个子界面
    //auto *childDialog = new QDialog(this);
    //绑定了MainWindow,只要MainWindow没被释放，子界面就不会直接被释放
    //childDialog->show();
    //但这种办法会导致如果不关闭主界面，那么点击按钮就会生成新子界面，界面会越生成越多，造成资源浪费
    qDebug() << "show child dialog" << Qt::endl;
    //一个避免重复创建的办法就是在MainWindow的构造函数里创建好子界面，在槽函数中只控制子界面的显示即可。
    _child_dialog->show();
    //hide函数，隐藏当前界面
    this->hide();

}

void MainWindow::showMainDialog()
{
    _child_dialog->hide();
    this->show();
}
