#include "wizard.h"
#include "ui_wizard.h"

Wizard::Wizard(QWidget *parent)
    : QWizard(parent)
    , ui(new Ui::Wizard)
{
    ui->setupUi(this);
}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::done(int result)
{
    //在Wizard界面点击确认后，宣布完成，把name和path通过函数和信号传给mainwindow,然后再通过目录树构建出目录
    if (result == QDialog::Rejected) {
        return QWizard::done(result);
    }

    QString name, path;
    ui->wizardPage1->GetProSettings(name, path);
    emit SigProSettings(name, path);
    QWizard::done(result);
}
