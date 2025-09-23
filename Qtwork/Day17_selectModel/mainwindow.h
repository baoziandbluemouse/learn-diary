#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>

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
public slots:
    void getCurrentItemData();
    void toggleSelection();
    void updateSelection(const QItemSelection& selected, const QItemSelection& deselected);
    void changeCurrent(const QModelIndex& current, const QModelIndex& previous);
private:
    Ui::MainWindow *ui;
    QTableView * _table_view;
};
#endif // MAINWINDOW_H
