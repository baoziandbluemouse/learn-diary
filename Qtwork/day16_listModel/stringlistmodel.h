#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class StringListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit StringListModel(const QStringList & strings,QObject *parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    bool insertRows(int position, int rows,
                    const QModelIndex & index = QModelIndex());
    bool removeRows(int position, int rows,
                    const QModelIndex & index = QModelIndex());
    Qt::ItemFlags flags(const QModelIndex& index) const override; //flags用来告诉index索引指向的位置是允许编辑还是只显示
    bool setData(const QModelIndex& index,
                                  const QVariant &value, int role );
private:
    QStringList stringList;
};

#endif // STRINGLISTMODEL_H
