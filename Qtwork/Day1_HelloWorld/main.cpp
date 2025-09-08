#include <QApplication>
#include <QDialog>
#include <QLabel>
#include "hellodialog.h"

int main(int argc,char* argv[])
{
    QApplication a(argc,argv);
    //QLabel label(&w);
    // label.setText("Hello,World!");
    // w.show();
    // w.resize(400,300);
    // label.move(120,120);
    //Ui::Dialog ui;
    //ui.setupUi(&w);
    //w.show();
    HelloDialog dialog;
    dialog.show();
    return a.exec();
}
