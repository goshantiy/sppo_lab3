#include "charts.h"
#include <QBarSet>
charts::charts()
{

}
void charts::updateModel(QList<Data> model)
{
    auto series = convertData(model);
       updateChart(series);
}
void charts::updateChart(QAbstractSeries* series)
{
    charts_->removeAllSeries();
    charts_->addSeries(series);
}
