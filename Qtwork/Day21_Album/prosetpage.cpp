#include "prosetpage.h"
#include <QDir>
#include <QLineEdit>
#include "ui_prosetpage.h"
ProSetPage::ProSetPage(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::ProSetPage)
{
    ui->setupUi(this);
    registerField("proPath", ui->lineEdit_2);
    registerField("proName*", ui->lineEdit); //表*号代表这是一个必填的
    connect(ui->lineEdit,
            &QLineEdit::textEdited,
            this,
            &ProSetPage::completeChanged); //发出信号进入iscomplete函数，在这个函数里面处理输入是否正确
    connect(ui->lineEdit_2, &QLineEdit::textEdited, this, &ProSetPage::completeChanged);
    QString curPath = QDir::currentPath();
    ui->lineEdit_2->setText(curPath);
    ui->lineEdit_2->setCursorPosition(
        ui->lineEdit_2->text()
            .size()); //在用户输入或修改文本后，确保光标始终保持在文本的最末端，提升用户体验。
    ui->lineEdit->setClearButtonEnabled(true); //输入文本后，出现一个清除文本的按钮
    ui->lineEdit_2->setClearButtonEnabled(true);
}

ProSetPage::~ProSetPage()
{
    delete ui;
}

bool ProSetPage::isComplete() const
{
    //先判空，如果空不算完成
    if (ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "") {
        return false;
    }

    //判断是否文件夹是否合理
    QDir dir(ui->lineEdit_2->text());
    if (!dir.exists()) {
        //qDebug()<<"file path is not exists" << endl;
        ui->tips->setText("project path is not exists");
        return false;
    }

    //判断路径是否存在
    QString absFilePath = dir.absoluteFilePath(ui->lineEdit->text());

    //不能在一个已经存在的目录创建项目
    QDir dist_dir(absFilePath);
    if (dist_dir.exists()) {
        ui->tips->setText("project has exists, change path or name!");
        return false;
    }

    ui->tips->setText("");
    return QWizardPage::isComplete(); //如果还想用基类的函数，就在结尾调用一次基类的函数
}
