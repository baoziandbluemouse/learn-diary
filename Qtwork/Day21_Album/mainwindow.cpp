#include "mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QMenu>
#include "protree.h"
#include "ui_mainwindow.h"
#include "wizard.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建文件菜单
    QMenu * menu_file = menuBar()->addMenu(tr("文件(&F)"));
    //创建项目动作
    QAction * act_create_pro = new QAction(QIcon(":/icon/createpro.png"),tr("创建项目"),this);
    //添加快捷键
    act_create_pro->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    menu_file->addAction(act_create_pro);

    //打开项目动作以及添加快捷键
    QAction * act_open_pro = new QAction(QIcon(":/icon/openpro.png"),tr("打开项目"),this);
    act_open_pro->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_Q));
    menu_file->addAction(act_open_pro);

    //创建设置菜单
    QMenu * menu_set = menuBar()->addMenu(tr("设置(&S)"));
    //设置背景音乐
    QAction * act_music = new QAction(QIcon(":/icon/music.png"),tr("背景音乐"),this);
    act_music->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_M));
    menu_set->addAction(act_music);

    //连接信号和槽
    //连接创建项目槽函数
    connect(act_create_pro, &QAction::triggered, this, &MainWindow::SlotCreatePro);
    //连接打开项目的槽函数
    connect(act_open_pro, &QAction::triggered, this, &MainWindow::SlotOpenPro);

    //创建目录树
    _protree = new ProTree();
    ui->proLayout->addWidget(_protree);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotCreatePro(bool)
{
    qDebug()<<"slot Create Pro triggered"<<Qt::endl;
    Wizard wizard(this);
    wizard.setWindowTitle(tr("创建项目"));
    auto *page = wizard.page(0);
    page->setTitle(tr("设置项目配置"));
    //连接信号和槽，把项目配置传回来todo...
    connect(&wizard,
            &Wizard::SigProSettings,
            dynamic_cast<ProTree *>(_protree),
            &ProTree::AddProToTree); //由于_protree是基类指针，所以要用安全转换才能连接信号和槽
    wizard.show();
    wizard.exec();

    //断开所有信号todo..
    disconnect(&wizard);
}

void MainWindow::SlotOpenPro(bool)
{

}
