#include "piechart.h"

pieChart::pieChart(QWidget* parent, QList<Data> data)
{
charts_=new QChart();
charts_->setTheme(QChart::ChartTheme::ChartThemeBrownSand);
charts_->legend()->setAlignment(Qt::AlignRight);

}
QAbstractSeries* pieChart::convertData(QList<Data> model)
{
    const auto series = new QPieSeries;
    for (const auto& it : model)
    {
        const auto label = it.name + " " + QString::number(it.percentage, 'f', 3) + "%";
        const auto value = it.percentage;
        const auto set = new QBarSet(label);
        const auto slice = new QPieSlice(label, value);
        series->append(slice);
        set->append(it.percentage);
    }
    return series;
}
QChart *pieChart::getChart()
{
    return charts_;
}
