#ifndef MYEDIT_H
#define MYEDIT_H
#include <QLineEdit>
#include <QWidget>
#include <QKeyEvent>
#include <QEvent>

class MyEdit:public QLineEdit
{
    Q_OBJECT
public:
    explicit MyEdit(QWidget * parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *);
    bool event(QEvent * pevent);
signals:

public slots:
};

#endif // MYEDIT_H
