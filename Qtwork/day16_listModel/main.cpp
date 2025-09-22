#include "mainwindow.h"
#include "stringlistmodel.h"
#include <QListView>
#include <QTableView>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList list;
    list <<"a"<<"b"<<"c";
    StringListModel model(list);
    QListView  listView;
    listView.setModel(&model);
    listView.show();

    QTableView tableView;
    tableView.setModel(&model);
    tableView.show();

    model.insertRows(3,2); //在第三行后插入两行
    model.removeRows(0,1); //在第零行开始删除一行

    return a.exec();
}
