#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPixmap>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QAbstractItemView>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTreeWidget * _treeWidget;
    QTableWidget * _tableWidget;
};
#endif // MAINWINDOW_H
