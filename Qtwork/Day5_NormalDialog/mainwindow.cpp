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
#include <QProgressDialog>
#include <QTimer>
#include <QWizard>
#include <QWizardPage>
#include <QLabel>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _count=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_updateProgressDialog()
{
    //主要作用就是定时更新进度条
    //到顶了就结束回收资源了
    _count++;
    if(_count > 5000){
        _timer->stop();
        delete  _timer;
        _timer = nullptr;
        delete _progressDialog;
        _progressDialog = nullptr;
        _count = 0;
        return;
    }

    _progressDialog->setValue(_count);
}

void MainWindow::on_cancelProgressDialog()
{
    _timer->stop();
    delete  _timer;
    _timer = nullptr;
    delete _progressDialog;
    _progressDialog = nullptr;
    _count = 0;
    qDebug()<<"cancel"<<Qt::endl;
    return;
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


void MainWindow::on_pushButton_4_clicked()
{
    //改用定时器
    _progressDialog = new QProgressDialog(tr("正在复制"),tr("取消复制"),0,5000,this);
    _progressDialog->setWindowTitle(tr("文件复制进度对话框"));
    _progressDialog->setWindowModality(Qt::ApplicationModal);
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &MainWindow::on_updateProgressDialog);
    //下面的connect是当我们取消复制时，进行的回收资源方式
    connect(_progressDialog, &QProgressDialog::canceled, this, &MainWindow::on_cancelProgressDialog);
    _timer->start(2);
    qDebug("复制结束");
}









void MainWindow::on_pushButton_6_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("全城热恋"));

    QWizardPage* page1 = new QWizardPage();
    page1->setTitle(tr("婚恋介绍引导程序"));
    auto label1 = new QLabel();
    label1->setText(tr("程序目的帮助您找到人生伴侣"));
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label1);
    page1->setLayout(layout);
    wizard.addPage(page1);

    QWizardPage* page2 = new QWizardPage();
    page2->setTitle("选择心动类型");
    QButtonGroup *group = new QButtonGroup(page2);
    QRadioButton * btn1 = new QRadioButton();
    btn1->setText("白富美");
    group->addButton(btn1);
    QRadioButton * btn2 = new QRadioButton();
    btn2->setText("萝莉");
    group->addButton(btn2);
    QRadioButton * btn3 = new QRadioButton();
    btn3->setText("御姐");
    group->addButton(btn3);
    QRadioButton * btn4 = new QRadioButton();
    btn4->setText("小家碧玉");
    group->addButton(btn4);
    QRadioButton * btn5 = new QRadioButton();
    btn5->setText("女汉子");
    group->addButton(btn5);
    QRadioButton * btn6 = new QRadioButton();
    btn6->setText("成年人不做选择，全选!");
    group->addButton(btn6);
    QVBoxLayout *vboxLayout2 = new QVBoxLayout();
    for(int i=0;i<group->buttons().size();i++){
        vboxLayout2->addWidget(group->buttons()[i]);
    }
    page2->setLayout(vboxLayout2);
    wizard.addPage(page2);

    QWizardPage* page3 = new QWizardPage();
    page3->setTitle(tr("你的缘分即将到来"));
    auto label3 = new QLabel();
    label3->setText(tr("感谢您的参与，接下来的一个月会遇到对的人"));
    QVBoxLayout *layout3 = new QVBoxLayout();
    layout3->addWidget(label3);
    page3->setLayout(layout3);
    wizard.addPage(page3);

    wizard.show();
    wizard.exec();
}

