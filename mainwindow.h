#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFileSystemModel>
#include <QTableView>
#include <filebrowsermodel.h>
#include <data.h>
#include <byfile.h>
#include <bytype.h>
#include <controlstrategy.h>
namespace Ui
{
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
void treeViewCollapsedOrExpanded();
void on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected);
void actionChange(int);

signals:
    void updateModel(QList<Data> model);
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    controlStrategy* strategy;
    QList<Data> dataModel;
    fileBrowserModel *fileModel;
    QFileSystemModel *dirModel;
    QTableView *tableView;
    QString curDir;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
