#ifndef CHILDDIALOG_H
#define CHILDDIALOG_H

#include <QDialog>
namespace Ui {
class ChildDialog;
}

class ChildDialog : public QDialog
{
    Q_OBJECT
signals:
    void showMainSig();//为ChildDialog类声明一个信号，用来通知主界面显示
public:
    explicit ChildDialog(QWidget *parent = nullptr);
    ~ChildDialog();
public slots:
    void showMainWindow();
private:
    Ui::ChildDialog *ui;
    //QWidget * _parent;
    //这种用指针来调用界面的方法有点太麻烦了，如果界面多，那么就要添加很多成员
    //我们引入信号和槽机制，当我们点击子界面按钮时发送一个信号给主界面，这样主界面收到该信号后就显示主界面隐藏子界面。
};

#endif // CHILDDIALOG_H
