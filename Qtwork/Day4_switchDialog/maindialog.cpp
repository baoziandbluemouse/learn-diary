#include "maindialog.h"
#include "ui_maindialog.h"
#include "childdialog.h"
MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_switchBtn_clicked()
{
    close();
    //close函数只会把界面隐藏，由于Qt的回收机制，只有当没有可以显示的界面时，
    //所有资源才会被回收
    qDebug()<<"switch to the child dialog"<<Qt::endl;
    ChildDialog c;
    if(c.exec() == QDialog::Accepted){
        this->show();
    }else{
        qDebug()<<"exit the dialog"<<Qt::endl;
        return;
    }
}

