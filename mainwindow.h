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
#include <charts.h>
#include <QChartView>
#include <piechart.h>
#include <barchart.h>
#include <stackedbar.h>
#include <imodel.h>
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
void viewChange(int);

signals:
    void updateModel(QList<Data> model);
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    IModel* model;
    QWidget* view;
    controlStrategy* strategy;
    QList<Data> dataModel;
    fileBrowserModel *fileModel;
    QFileSystemModel *dirModel;
    QTableView *tableView;
    QString curDir;
    Ui::MainWindow *ui;
    barChart* bar;
    pieChart* pie;
    stackedBar* stack;
    QChartView *pieView;
    QChartView *barView;
    QChartView *stackView;
};

#endif // MAINWINDOW_H
