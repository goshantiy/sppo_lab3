#include "filebrowsermodel.h"

fileBrowserModel::fileBrowserModel(QObject* parent,const QList<Data>& data)
    :QAbstractTableModel(parent),model_(data){}
int fileBrowserModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return model_.count();
}
int fileBrowserModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    int columns=3;
    return columns;
}
QVariant fileBrowserModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || model_.count() <= index.row() || (role != Qt::DisplayRole && role != Qt::EditRole))
    {
        return QVariant();
    }
    switch(index.column())
    {
        case 0:
        {
            return model_[index.row()].name;
        }
        case 1:
        {
            return model_[index.row()].size;
        }
        case 2:
        {
            if(model_[index.row()].size == 0)
                return 0;
            if(model_[index.row()].percentage > 0.01)
                return floor(model_[index.row()].percentage*100)/100;
            else
            return "<0,01";
        }
    }
    return QVariant();
}
QVariant fileBrowserModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role!=Qt::DisplayRole)
        return QVariant();
    if(orientation==Qt::Horizontal)
    {
        switch(section)
        {
        case 0:return "Название";
        case 1:return "Размер";
        case 2:return "Процент";
        }
    }
    return QVariant();
}
void fileBrowserModel::updateModel(QList<Data> model)
{
    beginResetModel();
    model_ = model;
    endResetModel();
}


