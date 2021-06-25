#ifndef FILEBROWSERMODEL_H
#define FILEBROWSERMODEL_H
#include <QAbstractTableModel>
#include <data.h>

class fileBrowserModel: public QAbstractTableModel
{
public:
    fileBrowserModel(QObject* parent,const QList<Data>& data=QList<Data>());
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void updateModel(QList<Data>);
private:
    QList<Data> model_;
 };

#endif // FILEBROWSERMODEL_H
