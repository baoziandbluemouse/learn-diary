#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QFileDialog>
#include <QInputDialog>
#include <QStringList>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_colorBtn_clicked()
{
    QColorDialog colordlg(Qt::blue,this);
    colordlg.setOption(QColorDialog::ShowAlphaChannel);
    colordlg.exec();
    QColor color = colordlg.currentColor();
    qDebug()<<"color is:"<<color<<Qt::endl;
}


void MainWindow::on_textBtn_clicked()
{
    QString path = QDir::currentPath();
    QString title = tr("文件对话框");
    QString filter = tr("文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)");
    QString aFileName = QFileDialog::getOpenFileName(this,title,path,filter);

    qDebug() << aFileName << Qt::endl;
}


void MainWindow::on_inputintBtn_clicked()
{
    bool ok = false;
    auto intdata = QInputDialog::getInt(this,tr("数字输入对话框"),tr("请输入数字"),200,-200,400,10,&ok);
    //标题，文本，初始值，下限，上限，step一次加多少，bool为true是返回值
    if(ok){
        qDebug() << intdata << Qt::endl;
    }
}


void MainWindow::on_pushButton_clicked()
{
    bool ok = false;
    auto floatdata = QInputDialog::getDouble(this,tr("浮点数输入对话框"),tr("输入浮点数"),0.1,-2,4,1,&ok);
    if(ok){
        qDebug() << floatdata << Qt::endl;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QStringList items;
    items<<tr("条目1")<<tr("条目2");
    bool ok = false;
    auto itemData = QInputDialog::getItem(this,tr("条目对话框"),tr("输入或选择条目"),items,0,true,&ok);
    if(ok){
        qDebug()<<"item is "<<itemData<<Qt::endl;
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    auto ret = QMessageBox::question(this,tr("提问对话框"),tr("你是单身吗？"));
    if(ret == QMessageBox::Yes){
        qDebug() <<"ret is " << ret;
        qDebug() <<"you are single" << Qt::endl;
    }else{
        return;
    }

    auto ret2 = QMessageBox::information(this,tr("通知对话框"),tr("你好单身狗"),QMessageBox::Yes);
    if(ret2 == QMessageBox::Yes){
        qDebug()<<"ret2 is "<<ret2;
    }else{
        return;
    }

    auto ret3 = QMessageBox::warning(this,tr("警告对话框"),tr("你最好找个地方发泄一下"),QMessageBox::Ok);
    if(ret3 == QMessageBox::Ok){
        qDebug() << "ret3 is " << ret3 << Qt::endl;
    }

    auto ret4 = QMessageBox::critical(this,tr("关键提示对话框"), tr("我梦寐以求是真爱和自由"),QMessageBox::Ok);
    if(ret4 == QMessageBox::Ok){
        qDebug() << "ret4 is " << ret4 << Qt::endl;
    }


}

