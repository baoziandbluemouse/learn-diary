#include "maindialog.h"
#include "childdialog.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDialog w;
    ChildDialog c;
    auto res = c.exec();
    if(res == QDialog::Accepted){
        w.show();
        return a.exec();
    }else{
        qDebug()<<"Child Dialog exit,res is :"<<res<<Qt::endl;
        return 0;
    }
}
