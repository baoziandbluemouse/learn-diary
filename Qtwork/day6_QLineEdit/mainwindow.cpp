#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QRegularExpression>
#include <QRegularExpressionValidator>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->ip_edit->setEchoMode(QLineEdit::Normal);
    QString ip_mask = "000.000.000.000;_";  //输入ip地址时可以使用的过滤
    ui->ip_edit->setInputMask(ip_mask);
    ui->mac_edit->setEchoMode(QLineEdit::Normal);
    QString mac_mask = "HH:HH:HH:HH;_"; //输入mac地址时可以使用的过滤
    ui->mac_edit->setInputMask(mac_mask);

     ui->pw_edit->setEchoMode(QLineEdit::Password);//让密码看不见的函数

    //过滤邮箱的正则表达式，旧版本使用QRegExp(Qt5)
     QRegularExpression regx("[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+");
     QRegularExpressionValidator *validator = new QRegularExpressionValidator(regx,ui->emailedit);
     ui->emailedit->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}
