#include "protree.h"
#include "ui_protree.h"

ProTree::ProTree(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProTree)
{
    ui->setupUi(this);
    this->setMinimumHeight(478);
    this->setMaximumHeight(478);
}

ProTree::~ProTree()
{
    delete ui;
}

void ProTree::AddProToTree(const QString name, const QString path)
{
    ui->treeWidget->AddProToTree(name, path);
}
