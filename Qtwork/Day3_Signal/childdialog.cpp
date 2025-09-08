#include "childdialog.h"
#include "ui_childdialog.h"

ChildDialog::ChildDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChildDialog)
    //, _parent(parent)
{
    ui->setupUi(this);
    connect(ui->showMainButton,&QPushButton::clicked,this,&ChildDialog::showMainWindow);
    //connect还有提供将信号与信号链接在一起的重载，用这种方法就不必再专门写个函数去发出信号了
}

ChildDialog::~ChildDialog()
{
    delete ui;
}

void ChildDialog::showMainWindow()
{
    qDebug()<<"show main window"<<Qt::endl;
    //this->hide();
    //_parent->show();
    //可以再次发送信号通知主窗口显示
    emit showMainSig();
}
