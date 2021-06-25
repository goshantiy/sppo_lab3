#include "mainwindow.h"
#include <QSplitter>
#include <QListView>
#include <QTreeView>
#include <QTextEdit>
#include <QFileSystemModel>
#include <QItemSelectionModel>
#include <QVBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QStatusBar>
#include <QDebug>
#include <ui_mainwindow.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      strategy(new controlStrategy(new byFile))
{
      ui->setupUi(this);
      curDir="C:/Users/PC/Documents/testLab3";
      fileModel=new fileBrowserModel(this, strategy->doStrategy(curDir));
      tableView = new QTableView(this);
      tableView->setModel(fileModel);
      ui->horizontalLayout_4->addWidget(tableView);
      tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
      ui->treeView->header()->setSectionResizeMode(QHeaderView::Stretch);
      dirModel=new QFileSystemModel(this);
      dirModel->setFilter(QDir::NoDotAndDotDot|QDir::AllDirs);
      dirModel->setRootPath("C:/");
      ui->treeView->setModel(dirModel);

      connect(ui->treeView,SIGNAL(expanded(const QModelIndex )),this,SLOT(treeViewCollapsedOrExpanded()));
      connect(ui->treeView,SIGNAL(collapsed(const QModelIndex )),this,SLOT(treeViewCollapsedOrExpanded()));

      connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(actionChange(int)));

      QItemSelectionModel *selectionModel = ui->treeView->selectionModel();

      connect(selectionModel, SIGNAL(selectionChanged(const QItemSelection , const QItemSelection )),
              this, SLOT(on_selectionChangedSlot(const QItemSelection , const QItemSelection )));
}
void MainWindow::actionChange(int ix)
{
    switch(ix)
    {
    case 0:
        strategy->setStrategy(new byFile);
        break;
    case 1:
        strategy->setStrategy(new byType);
        break;
   }

    fileModel->updateModel(strategy->doStrategy(curDir));
}
void MainWindow::on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);

    QModelIndexList indexs =  selected.indexes();

    if (indexs.count() >= 1) {
        QModelIndex ix =  indexs.constFirst();
        curDir = dirModel->filePath(ix);
        this->statusBar()->showMessage("Выбранный путь : " + curDir);
    }

    fileModel->updateModel(strategy->doStrategy(curDir));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::treeViewCollapsedOrExpanded()
{
    ui->treeView->resizeColumnToContents(0);
}



