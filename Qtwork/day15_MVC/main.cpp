#include "mainwindow.h"

#include <QApplication>
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>

//MVC 就是Model-View-Control模式的简称，包括模型层(Model), 视图层(View), 控制层(Controller).
//Model主要负责管理数据，View主要用来显示数据，Controller主要用来操作数据，控制View联动。
//Qt也采用了这个模式，模型层用Model，视图层用View，控制层改名叫了代理Delegate。
//模型分为几种，有列表模型，表格模型，以及树模型。

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    QSplitter * splitter  = new QSplitter;
    QFileSystemModel * model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    //如果model不绑定目录的话，那后面tree和list就算设置了索引，也不会有任何目录出现

    QTreeView * tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));
    //index返回当前目录的索引，以此让tree能显示当前目录,下面list也是如此
    //如果不设置，默认就是系统目录

    auto *list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

    splitter->setWindowTitle("Two views onto the same file system model");
    splitter->resize(1000,800);
    splitter->show();
    //splitter会将加入的视图自动进行分割

    return a.exec();
}
