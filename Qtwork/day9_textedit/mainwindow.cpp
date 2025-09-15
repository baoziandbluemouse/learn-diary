#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextDocument>
#include <QTextFrame>
#include <QTextFrameFormat>
#include <QTextCursor>
#include <QAction>
#include <QDebug>
#include <QTextBlockFormat>
#include <QTextCharFormat>
#include <QTextTableFormat>
#include <QTextListFormat>
#include <QTextImageFormat>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //添加了textedit插件，然后在MainWindow的构造函数修改文本框样式
    QTextDocument * doc = ui->textEdit->document();
    //通过textEdit的document函数返回文本块，再通过rootFrame获取根框架，设置这个框架的边框样式为蓝色，边框为3.
    //运行程序后可以看到主窗口的textedit会显示一个蓝色边框的输入框，那就是根节点。我们可以插入两个纯文本
    QTextFrame* root_frame = doc->rootFrame();
    QTextFrameFormat format;
    format.setBorderBrush(Qt::blue);
    format.setBorder(3);
    root_frame->setFrameFormat(format);

    QTextFrameFormat  frameFormat;
    frameFormat.setBackground(Qt::lightGray);
    frameFormat.setMargin(10);
    frameFormat.setPadding(5);
    frameFormat.setBorder(2);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dashed);
    QTextCursor cursor = ui->textEdit->textCursor();//获取光标
    cursor.insertFrame(frameFormat); //在光标处插入这个框架
    ui->textEdit->insertPlainText("inner text!\n");
    ui->textEdit->insertPlainText("Hello inner Text!\n");
    //我们可以遍历文本块和框架节点。先在构造函数中添加一个菜单，用来打印Frame和TextBlock
    QAction * action_frame = new QAction("Frame",this);
    connect(action_frame, &QAction::triggered,this, &MainWindow::showTextFrame);
    ui->toolBar->addAction(action_frame);
    QAction* action_textBlock = new QAction(tr("文本块"),this);
    connect(action_textBlock, &QAction::triggered, this, &MainWindow::showTextBlock);
    ui->toolBar->addAction(action_textBlock);

    //设置文本块的样式
    QAction* action_font = new QAction(tr("字体"), this);
    action_font->setCheckable(true);
    connect(action_font, &QAction::toggled, this, &MainWindow::setTextFont);
    ui->toolBar->addAction(action_font);

    //插入表格，列表，图片
    QAction* action_textTable = new QAction(tr("表格"), this);
    QAction* action_textList = new QAction(tr("列表"), this);
    QAction* action_textImage = new QAction(tr("图片"), this);
    connect(action_textTable, &QAction::triggered,this, &MainWindow::insertTable);
    ui->toolBar->addAction(action_textTable);
    connect(action_textList, &QAction::triggered,this, &MainWindow::insertList);
    ui->toolBar->addAction(action_textList);
    connect(action_textImage, &QAction::triggered,this, &MainWindow::insertImage);
    ui->toolBar->addAction(action_textImage);

    //查找
    QAction* action_textFind = new QAction(tr("查找"), this);
    connect(action_textFind, &QAction::triggered, this, &MainWindow::textFind);
    ui->toolBar->addAction(action_textFind);

    findDialog = new QDialog(this);
    lineEdit = new QLineEdit(findDialog);
    QPushButton * btn = new QPushButton(findDialog);
    btn->setText(tr("查找下一个"));
    connect(btn, &QPushButton::clicked, this, &MainWindow::findNext);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    findDialog->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTextFrame()
{
    auto doc = ui->textEdit->document();
    auto rootFrame = doc->rootFrame();
    for(auto it = rootFrame->begin();it!=rootFrame->end();it++)
    {
        auto cur_frame = it.currentFrame();
        auto cur_block = it.currentBlock();
        if(cur_frame){
            qDebug() << "cur node is frame " ;
        } else if(cur_block.isValid()){
            qDebug() << "cur node is text block ,text is " << cur_block.text();
        }
    }
}

void MainWindow::showTextBlock()
{
    QTextDocument* document = ui->textEdit->document();
    QTextBlock block = document->firstBlock();
    for(int i = 0; i < document->blockCount(); i++){
        qDebug() << tr("文本块%1, 文本块首行行号%2, 长度%3, 内容%4").arg(i)
                        .arg(block.firstLineNumber())
                        .arg(block.length())
                        .arg(block.text());
        block = block.next();
    }
}

void MainWindow::setTextFont(bool checked)
{
    //如果选中字体菜单，则设置插入新的文本块，文本块格式为宋体，加粗字样。
    //如果取消选中，则插入新的文本块，设置为微软雅黑字体。
    if(checked)
    {
        QTextCursor cursor = ui->textEdit->textCursor();
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(blockFormat);
        QTextCharFormat charFormat;
        charFormat.setBackground(Qt::lightGray);
        charFormat.setForeground(Qt::blue);
        charFormat.setFont(QFont(tr("宋体"),12,QFont::Bold,true));
        charFormat.setFontUnderline(true);
        cursor.setCharFormat(charFormat);
        cursor.insertText(tr("插入字体"));
    }else{
        QTextCursor cursor = ui->textEdit->textCursor();
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignLeft);
        cursor.insertBlock(blockFormat);
        QTextCharFormat charFormat;
        cursor.setCharFormat(charFormat);
        cursor.insertText(tr("微软雅黑字体"));
    }
}

void MainWindow::insertTable()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format;
    format.setCellSpacing(2);
    format.setCellPadding(10);
    cursor.insertTable(2,2,format);
}

void MainWindow::insertList()
{
    QTextListFormat format;
    format.setStyle(QTextListFormat::ListDecimal);
    ui->textEdit->textCursor().insertList(format);
}

void MainWindow::insertImage()
{

}

void MainWindow::textFind()
{
    findDialog->show();
}

void MainWindow::findNext()
{
    QString string = lineEdit->text();
    bool isFind = ui->textEdit->find(string,QTextDocument::FindBackward);
    if(isFind){
        qDebug()<<tr("行号:%1 列号:%2").arg(ui->textEdit->textCursor().blockNumber())
                        .arg(ui->textEdit->textCursor().columnNumber());
    }
}
