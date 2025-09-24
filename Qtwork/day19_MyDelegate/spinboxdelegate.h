#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H

#include <QItemDelegate>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QWidget>
#include <QSpinBox>

//当我们想重新实现一个代理时，可以子类化QItemDelegate。实现item编辑时特定的效果，比如在item编辑时我们设置一个QSpinBox返回。

class SpinBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    SpinBoxDelegate(QObject* parent = 0);

    //SpinBoxDelegate类中声明了几个函数，这些函数在QItemDelegate继承而来，通过重写实现我们自己定义的代理功能。
    //createEditor函数是在item被双击后进入编辑状态时触发的，返回一个QWidget控件用来管理编辑。
    //setModelData是在item被修改后触发的，将改动的内容写入model中。
    //setEditorData是在item被双击进入编辑状态时，将model的内容写入editor中。
    //updateEditorGeometry是刷新editor的矩形区域，因为随着item变大或者拉伸，它的区域也要随之刷新。
    // editing
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;

};

#endif // SPINBOXDELEGATE_H
