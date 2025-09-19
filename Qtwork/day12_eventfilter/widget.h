#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myedit.h"
#include <QWheelEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void keyPressEvent(QKeyEvent * event);
    bool eventFilter(QObject *object, QEvent *event);

private:
    Ui::Widget *ui;
    MyEdit * line_edit_;
};
#endif // WIDGET_H
