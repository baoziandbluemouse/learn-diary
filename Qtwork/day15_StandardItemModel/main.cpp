#include "mainwindow.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QPixmap>
#include <QTreeView>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    QStandardItemModel model;
    //QStandardItemModel有一个不可见的根节点，可以以这个类为基础实现树型模型
    //这个类是最基础的模型，还有一些集成化更高的模型能实现特定的树型模型，列表模型，网状模型之类
    //实现了树型模型后，再用TreeView显示就好了
    auto * parentItem = model.invisibleRootItem();
    //创建文本显示，图标，和工具显示
    QStandardItem * item0 = new QStandardItem();
    item0->setText("item0");
    QPixmap pixmap0(50,50);
    pixmap0.fill(Qt::red);
    item0->setIcon(pixmap0);
    item0->setToolTip("indexA");
    parentItem->appendRow(item0);
    //将新的项设置为父节点项
    parentItem = item0;

    //重复添加
    QStandardItem * item1 = new QStandardItem();
    item1->setText("item1");
    QPixmap pixmap1(50,50);
    pixmap1.fill(Qt::blue);
    item1->setIcon(pixmap1);
    item1->setToolTip("indexB"); //悬浮时显示提示
    parentItem->appendRow(item1);

    //通过setData来添加item
    QStandardItem * item2 = new QStandardItem();
    item2->setData("item2",Qt::EditRole);
    QPixmap pixmap2(50,50);
    pixmap2.fill(Qt::green);
    item2->setData(QIcon(pixmap2), Qt::DecorationRole);
    item2->setData("indexC",Qt::ToolTipRole); //提示
    parentItem->appendRow(item2);

    //通过index或者data来取出model中的数据
    //取出根节点第0行0列的模型索引
    QModelIndex indexA = model.index(0,0, QModelIndex());//参数分别是row,column,父节点
    //模型不能直接访问，得先用一个QModelIndex取出资源，再使用model的函数来获取数据
    qDebug() << "model indexA row count is " << model.rowCount(indexA);

    //获取indexA节点下0行0列
    //data函数也是同样，得先使用QModelIndex来取出资源，然后使用model.data()函数
    QModelIndex indexB = model.index(0,0,indexA);
    qDebug() << "indexB text is " << model.data(indexB,Qt::EditRole).toString();
    qDebug() << "indexB icon is " << model.data(indexB,Qt::DecorationRole);
    qDebug() << "indexB tool tip  is " << model.data(indexB,Qt::ToolTipRole).toString();

    QModelIndex indexC = model.index(1,0,indexA);
    qDebug() << "indexC text is " << model.data(indexC,Qt::EditRole).toString();
    qDebug() << "indexC icon is " << model.data(indexC,Qt::DecorationRole);
    qDebug() << "indexC tool tip  is " << model.data(indexC,Qt::ToolTipRole).toString();

    QTreeView view;
    view.setModel(&model);
    view.show();
    return a.exec();
}
