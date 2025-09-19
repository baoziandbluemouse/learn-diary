#include "widget.h"
#include "ui_widget.h"
#include <QCursor>
#include <QMouseEvent>
#include <QApplication>
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    //设置鼠标
    setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPosition().toPoint()-pos();

    }else if(event->button() == Qt::RightButton){
        QCursor cursor(QPixmap(":/res/favicon.ico"));
        QApplication::setOverrideCursor(cursor);
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    //释放事件
    QApplication::restoreOverrideCursor();
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        if(windowState() == Qt::WindowFullScreen){
            setWindowState(Qt::WindowNoState);
        }else{
            setWindowState(Qt::WindowFullScreen);
        }
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    //在鼠标移动过程中保证窗口也移动
    //移动过程中判断鼠标是左键点击并且移动，那么要用buttons，返回的是鼠标状态的集合
    if(event->buttons() & Qt::LeftButton){
        //获取窗口应当移动到的位置
        QPoint windowmove = event->globalPosition().toPoint()-offset;
        this->move(windowmove);
    }
}

void Widget::wheelEvent(QWheelEvent *event)
{
    auto delta = event->angleDelta().y();
    //鼠标滚动远离使用者放大textedit
    if(delta > 0){
        qDebug() << "catch wheel event delta > 0" << Qt::endl;
        ui->textEdit->zoomIn();
    }else {
        qDebug() << "catch wheel event delta < 0" << Qt::endl;
        ui->textEdit->zoomOut();
    }
}
