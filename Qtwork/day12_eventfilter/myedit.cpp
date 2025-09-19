#include "myedit.h"



MyEdit::MyEdit(QWidget *parent):QLineEdit(parent)
{

}

void MyEdit::keyPressEvent(QKeyEvent * event)
{
    qDebug()<<"MyEdit key press event";
    QLineEdit::keyPressEvent(event);
    event->ignore();
}

bool MyEdit::event(QEvent *pevent)
{
    if(pevent->type() == QEvent::KeyPress){
        qDebug()<<tr("my edit event")<<Qt::endl;
        //return false;
    }
    return QLineEdit::event(pevent);
}
