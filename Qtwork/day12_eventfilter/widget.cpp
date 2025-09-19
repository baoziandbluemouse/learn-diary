#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    line_edit_ = new MyEdit(this);
    line_edit_->move(100,100);
    line_edit_->installEventFilter(this);
    ui->textEdit->installEventFilter(this);
    ui->spinBox->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"Widget key press event" << Qt::endl;
}

bool Widget::eventFilter(QObject *object, QEvent *event)
{
    //要实现对某个控件事件的捕获，可以通过对其父窗口重写eventFilter函数
    //这个函数是过滤器，在这个过滤器里可以根据对象和事件类型进行。
    if(object == line_edit_){
        if(event->type() == QEvent::KeyPress){
            qDebug() << "widget eventfilter catch line_edit" <<Qt::endl;
            return false;
        }
    }

    if(object == ui->textEdit){
        if(event->type() == QEvent::Wheel){
            QWheelEvent * wheelEvent = static_cast<QWheelEvent*>(event);
            int delta = wheelEvent->angleDelta().y();
            if(delta > 0){
                qDebug() << "catch wheel event delta > 0" << Qt::endl;
                ui->textEdit->zoomIn();
            }else {
                qDebug() << "catch wheel event delta < 0" << Qt::endl;
                ui->textEdit->zoomOut();
            }
            //return true后，事件就停在这了，不会继续有其他效果，被拦截了
            return true;
        }
        return false;
    }

    if(object == ui->spinBox){
        if(event->type() == QEvent::KeyPress){
            QKeyEvent * keyEvent = static_cast<QKeyEvent*>(event);
            if(keyEvent->key() == Qt::Key_Space){
                ui->spinBox->setValue(0);
                return true;
            }
        }
        return false;
    }



    return QWidget::eventFilter(object, event);
}
