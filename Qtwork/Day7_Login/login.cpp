#include "login.h"
#include "ui_login.h"
#include "register.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::initSignals()
{
    _register = std::make_shared<Register>();
    //从本类转化为共享的智能指针给register类
    _register->set_login(shared_from_this());
}

void Login::on_pushButton_2_clicked()
{
    this->close();
    _register->show();
}

