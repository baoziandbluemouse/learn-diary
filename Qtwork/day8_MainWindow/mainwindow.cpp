#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QMenu>
#include <QIcon>
#include <QActionGroup>
#include "myacition.h"
#include <QToolButton>
#include <QSpinBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    QMenu* editMenu = ui->menubar->addMenu(tr("编辑(&E)"));
    editMenu->addSeparator();
    QAction * action_Open = editMenu->addAction(QIcon(":/img/head.jpg"), tr("打开文件(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    connect(action_Open,&QAction::triggered, this, &MainWindow::on_action_open_triggered);

    //建立动作组
    QActionGroup * group = new QActionGroup(this);
    QAction * action_L = group->addAction(tr("左对(&L)"));
    action_L->setCheckable(true);
    QAction * action_R = group->addAction(tr("右对(&R)"));
    action_R->setCheckable(true);
    QAction * action_C = group->addAction(tr("居中(&C)"));
    action_C->setCheckable(true);
    editMenu->addSeparator();
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

    MyAction *action = new MyAction(this);
    editMenu->addAction(action);
    connect(action,&MyAction::getText,this,&MainWindow::slot_set_text);

    //工具栏添加元素
    QToolButton * toolBtn = new QToolButton(this);
    toolBtn->setText(tr("颜色"));
    QMenu* colorMenu = new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->toolBar->addWidget(toolBtn);
    QSpinBox* spinBox = new QSpinBox(this);
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(spinBox);

    //状态栏在窗口的下方，一般在右下方，左下方的为临时的，右下方的为永久的。
    //显示临时消息
    ui->statusbar->showMessage(tr("欢迎使用多文档编辑器"),2000);

    //永久显示的标签
    QLabel* permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("llfc.club");
    ui->statusbar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionshowDock_M_triggered()
{
    qDebug()<<"显示dock widget"<<Qt::endl;
    ui->dockWidget->show();
}


void MainWindow::on_actionNew_File_N_triggered()
{
    QTextEdit * textEdit = new QTextEdit(this);
    auto childWindow = ui->mdiArea->addSubWindow(textEdit);
    childWindow->setWindowTitle(tr("文本编辑子窗口"));
    childWindow->show();
}


void MainWindow::on_actionopen_File_O_triggered()
{
    qDebug()<<"打开文件..."<<Qt::endl;
}

void MainWindow::on_action_open_triggered()
{
    qDebug()<<"打开文件..."<<Qt::endl;
}

void MainWindow::slot_set_text(const QString &str)
{
    ui->textEdit->setText(str);
}

