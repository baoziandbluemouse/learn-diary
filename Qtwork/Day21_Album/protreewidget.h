#ifndef PROTREEWIDGET_H
#define PROTREEWIDGET_H

#include <QAction>
#include <QTreeWidget>

class ProTreeWidget : public QTreeWidget
{
public:
    ProTreeWidget(QWidget *parent = nullptr);
    void AddProToTree(const QString &name, const QString &path);

private:
    QSet<QString> _set_path;
    //右键单击某个item之后弹出菜单
    QTreeWidgetItem *_right_btn_item;
    QAction *_action_import;
    QAction *_action_setstart;
    QAction *_action_closepro;
    QAction *_action_slideshow;
private slots:
    void slotItemPressed(QTreeWidgetItem *pressedItem, int column);
    void SlotImport();
};

#endif // PROTREEWIDGET_H
