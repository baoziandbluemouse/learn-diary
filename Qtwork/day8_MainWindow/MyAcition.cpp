#include "MyAcition.h"
#include <QSplitter>
#include <QLabel>

MyAction::MyAction(QObject *parent):QWidgetAction(parent)
{
    //创建行编辑器
    lineEdit = new QLineEdit();
    // 将行编辑器的按下回车键信号和发送文本槽关联
    connect(lineEdit, &QLineEdit::returnPressed, this, &MyAction::sentText);
}

QWidget *MyAction::createWidget(QWidget *parent)
{
    if(parent->inherits("QMenu")|| parent->inherits("QToolBar")){
        QSplitter * spliter = new QSplitter(parent);
        QLabel * label = new QLabel;
        label->setText(tr("插入文本:"));
        spliter->addWidget(label);
        spliter->addWidget(lineEdit);
        return spliter;
    }
    return 0;
}

void MyAction::sentText()
{
    //把文本发送
    emit getText(lineEdit->text());
    lineEdit->clear();
}
