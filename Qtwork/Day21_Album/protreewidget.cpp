#include "protreewidget.h"
#include <QDir>
#include <QGuiApplication>
#include <QMenu>
#include "const.h"
#include "protreeitem.h"
ProTreeWidget::ProTreeWidget(QWidget *parent)
{
    this->setHeaderHidden(true);
    connect(this, &ProTreeWidget::itemPressed, this, &ProTreeWidget::slotItemPressed);
    _action_import = new QAction(QIcon(":/icon/import.png"), tr("导入文件"), this);
    _action_setstart = new QAction(QIcon(":/icon/core.png"), tr("设置活动项目"), this);
    _action_closepro = new QAction(QIcon(":/icon/close.png"), tr("关闭项目"), this);
    _action_slideshow = new QAction(QIcon(":/icon/clideshow.png"), tr("轮播图播放"), this);
    connect(_action_import, &QAction::triggered, this, &ProTreeWidget::SlotImport);
}

void ProTreeWidget::AddProToTree(const QString &name, const QString &path)
{
    QDir dir(path);
    QString file_path = dir.absoluteFilePath(name);
    //检测重名，判断路径和名字都一样则拒绝加入
    if (_set_path.find(file_path) != _set_path.end()) {
        qDebug() << "file has loaded" << Qt::endl;
        return;
    }
    //构造项目用的文件夹
    QDir pro_dir(file_path);
    //如果文件夹不存在则创建
    if (!pro_dir.exists()) {
        bool enable = pro_dir.mkpath(file_path);
        if (!enable) {
            return;
        }
    }
    _set_path.insert(file_path);
    auto *item = new ProTreeItem(this, name, file_path, TreeItemPro);
    item->setData(0, Qt::DisplayRole, name);
    item->setData(0, Qt::DecorationRole, QIcon(":/icon/dir.png"));
    item->setData(0, Qt::ToolTipRole, file_path);
    this->addTopLevelItem(item);
}

void ProTreeWidget::slotItemPressed(QTreeWidgetItem *pressedItem, int column)
{
    if (QGuiApplication::mouseButtons() == Qt::RightButton) {
        QMenu menu(this);
        int itemtype = pressedItem->type();
        if (itemtype == TreeItemPro) {
            _right_btn_item = pressedItem;
        }
    }
}

void ProTreeWidget::SlotImport() {}
