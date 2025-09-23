#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QItemSelection>
#include <QDebug>

//Qt的MVC结构支持多个View共享同一个model，包括该model的选中状态等。
//我们可以通过设置QItemSelectionModel，来更改View的选中效果和显示效果。

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel * model = new QStandardItemModel(7,4,this);
    for(int row=0; row < 7; row++){
        for(int column = 0; column < 4; column++){
            QStandardItem * item = new QStandardItem(QString("%1").arg(row*4+column));
            model->setItem(row, column, item);
        }
    }

    _table_view = new QTableView;
    _table_view->setModel(model);
    setCentralWidget(_table_view);
    this->resize(800,800);

    //获取视图的项目选择模型
    QItemSelectionModel * selection_model =  _table_view->selectionModel();
    //定义左上角和右下角的索引
    QModelIndex topLeft;
    QModelIndex bottomRight;
    //根据上面两个索引选择项目
    //第1行1列
    topLeft = model->index(1,1,QModelIndex());
    //第5行2列
    bottomRight = model->index(5,2,QModelIndex());
    //设置选择区域
    QItemSelection selection(topLeft, bottomRight);
    //将选择的区域设置给选择模型, 设置 为选中状态
    selection_model->select(selection, QItemSelectionModel::Select);

    //如之前所说，模型可以被多个view共享,在一个view上做选择可以同步给别的view
    // QTableView * tableview2;
    // tableview2 = new QTableView();
    // tableview2->setWindowTitle("tableview2");
    // tableview2->resize(400,300);
    // tableview2->setModel(model);
    // tableview2->setSelectionModel(selection_model);
    // tableview2->show();

    ui->MainToolBar->addAction(tr("展示当前项目"),this,&MainWindow::getCurrentItemData);
    ui->MainToolBar->addAction(tr("切换选中"),this,&MainWindow::toggleSelection);

    //捕获选择条目的变化
    //当我们点击鼠标选择一个条目时，当前条目就变为该条目，选择的条目也变为该条目。
    //可以通过选择模型发出的selectionChanged信号，获取选择了那些条目的索引，以及取消选择了哪些条目的索引。
    //捕获后，我们就可以对自己选择的条目进行些更新操作,并且上一个被选择的条目，也可以捕获并更新
    //选择模型的选择条目更改后触发updateSelection函数
    connect(selection_model, &QItemSelectionModel::selectionChanged, this, &MainWindow::updateSelection);
    //选择模型的当前项目更改后，关联changeCurrent函数
    connect(selection_model, &QItemSelectionModel::currentChanged, this, &MainWindow::changeCurrent);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getCurrentItemData()
{
    //getCurrentItemData获取当前条目的数据信息(就是选择的条目)
    auto currentData = _table_view->selectionModel()->currentIndex().data().toString();
    qDebug()<<"当前项目内容:"<<currentData<<Qt::endl;
}

void MainWindow::toggleSelection()
{
    //toggleSelection实现切换选择的条目
    //找到根节点下第0行0列的item的索引
    QModelIndex topLeft = _table_view->model()->index(0,0,QModelIndex());
    //获取根节点下最大的行号
    auto max_row = _table_view->model()->rowCount(QModelIndex());
    //获取根节点下最大的列号
    auto max_column = _table_view->model()->columnCount(QModelIndex());
    //根据列号和行号获取最右下角的item的索引
    QModelIndex bottomRight = _table_view->model()->index(max_row-1, max_column-1, QModelIndex());
    //设置选择区域
    QItemSelection curSelection(topLeft, bottomRight);
    _table_view->selectionModel()->select(curSelection, QItemSelectionModel::Toggle);
}

void MainWindow::updateSelection(const QItemSelection &selected, const QItemSelection &deselected)
{
    QModelIndex index;
    QModelIndexList list = selected.indexes();
    //为现在的选择项目设置值
    for(int i =0; i < list.size(); i++){
        QString text = QString("(%1, %2)").arg(list[i].row()).arg(list[i].column());
        _table_view->model()->setData(list[i], text);
    }

    //deselected是上一次选中后变成没被选中的区域,把他换成空格，实现一个遮掩的机制
    list = deselected.indexes();
    foreach(index, list){
        _table_view->model()->setData(index,"");
    }
}

void MainWindow::changeCurrent(const QModelIndex &current, const QModelIndex &previous)
{
    qDebug()<<tr("move(%1,%2) to (%3,%4)").arg(previous.row()).arg(previous.column()).arg(current.row()).arg(current.column());
}
