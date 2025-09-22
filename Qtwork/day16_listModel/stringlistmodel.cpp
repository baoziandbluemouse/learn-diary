#include "stringlistmodel.h"


StringListModel::StringListModel(const QStringList &strings, QObject *parent):QAbstractListModel(parent), stringList(strings)
{

}

int StringListModel::rowCount(const QModelIndex &parent) const
{
    //返回列表模型的行数
    return stringList.count();
}

QVariant StringListModel::data(const QModelIndex &index, int role) const
{
    //如果索引无效，返回一个默认的QVariant，相当于一个空值
    if(!index.isValid()){
        return QVariant();
    }
    //如果这个行号越界了，也是返回一个空值,注意row是从0开始的，所以如果等于size也就是越界了
    if(index.row() >= stringList.size()){
        return QVariant();
    }
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        return stringList.at(index.row());//返回数据
    }
    //不是需要的role，返回空值
    return QVariant();
}

QVariant StringListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    //headerData函数内根据水平还是垂直判断，显示表头。
    if(role != Qt::DisplayRole){
        return QVariant();
    }

    if(orientation == Qt::Horizontal){
        return QString("Column %1").arg(section);
    }else{
        return QString("Row %1").arg(section);
    }
}

//添加行和删除行都需要在添加和删除之前调用begin操作，操作完之后调用end操作
bool StringListModel::insertRows(int position, int rows, const QModelIndex & index)
{
    beginInsertRows(QModelIndex(), position, position + rows -1);
    for(int row = 0; row < rows; ++ row){
        stringList.insert(position+row, QString::number(row));
    }
    endInsertRows();
    return true;
}

bool StringListModel::removeRows(int position, int rows, const QModelIndex & index)
{
    beginRemoveRows(QModelIndex(), position, position+ rows-1);
    for(int row=0; row < rows; ++ row){
        stringList.removeAt(position);
    }
    endRemoveRows();
    return true;
}

Qt::ItemFlags StringListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::ItemIsEnabled; //无效情况下，仅展示
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;  //使用基类的flags，获取一些基本的参数，然后再添加一个可以编辑的标识
}

bool StringListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //当我们修改数据时，会触发setData函数, 该函数根据项的角色为EditRole替换原来的字符串。
    //修改后告诉view视图，进行更新
    if(index.isValid() && role == Qt::EditRole){
        stringList.replace(index.row(), value.toString());
        emit dataChanged(index, index);//发出信号向view请求更新视图
        return true; //true代表可以在此结束，false的话会抛给其他上层函数，继续进行一些操作
    }
    return false;
}














