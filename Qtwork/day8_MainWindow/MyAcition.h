#ifndef MYACITION_H
#define MYACITION_H

#include <QWidgetAction>
#include <QLineEdit>
#include <QObject>
class MyAction : public QWidgetAction
{
    Q_OBJECT
signals:
    void getText(const QString& string);

public:

    explicit MyAction(QObject * parent = nullptr);
    //virtual ~MyAction();
protected:

    virtual QWidget *createWidget(QWidget *parent);

private slots:
    void sentText();
private:
    //声明行编辑器对象
    QLineEdit* lineEdit;
};

#endif // MYACITION_H
