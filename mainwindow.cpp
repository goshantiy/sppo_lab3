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
      QDir b(curDir);
      if(!b.isReadable())
       curDir=QDir::homePath();
      fileModel=new fileBrowserModel(this, strategy->doStrategy(curDir));
      model=fileModel;
      tableView = new QTableView(this);
      tableView->setModel(fileModel);
      ui->horizontalLayout_4->addWidget(tableView);
      tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
      ui->treeView->header()->setSectionResizeMode(QHeaderView::Stretch);
      view=tableView;
      bar=new barChart(this, strategy->doStrategy(curDir));
      pie=new pieChart(this, strategy->doStrategy(curDir));
      stack= new stackedBar(this, strategy->doStrategy(curDir));
      barView=new QChartView(bar->getChart());
      pieView=new QChartView(pie->getChart());
      stackView=new QChartView(stack->getChart());
      ui->horizontalLayout_4->addWidget(barView);
      ui->horizontalLayout_4->addWidget(pieView);
      ui->horizontalLayout_4->addWidget(stackView);
      barView->hide();
      pieView->hide();
      stackView->hide();
      dirModel=new QFileSystemModel(this);
      dirModel->setFilter(QDir::NoDotAndDotDot|QDir::AllDirs);
      dirModel->setRootPath("C:/");
      ui->treeView->setModel(dirModel);

      connect(ui->treeView,SIGNAL(expanded(const QModelIndex )),this,SLOT(treeViewCollapsedOrExpanded()));
      connect(ui->treeView,SIGNAL(collapsed(const QModelIndex )),this,SLOT(treeViewCollapsedOrExpanded()));

      connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(actionChange(int)));
      connect(ui->comboBox_2,SIGNAL(currentIndexChanged(int)),this,SLOT(viewChange(int)));

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

    model->updateModel(strategy->doStrategy(curDir));
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

    model->updateModel(strategy->doStrategy(curDir));
}
void MainWindow::viewChange(int display_id)
{
    view->hide();
    switch (display_id)
    {
    case 0:
        view = tableView;
        model = fileModel;
        model->updateModel(strategy->doStrategy(curDir));
        break;
    case 1:

        view = pieView;
        model = pie;
        model->updateModel(strategy->doStrategy(curDir));
        break;
    case 2:
        view = barView;
        model = bar;
        model->updateModel(strategy->doStrategy(curDir));
        break;
     case 3:
        view = stackView;
        model = stack;
        model->updateModel(strategy->doStrategy(curDir));
        break;

    }
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::treeViewCollapsedOrExpanded()
{
    ui->treeView->resizeColumnToContents(0);
}



