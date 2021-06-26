#include "stackedbar.h"

stackedBar::stackedBar(QWidget* parent, QList<Data> data)
{
charts_=new QChart;
charts_->setTheme(QChart::ChartTheme::ChartThemeBrownSand);
charts_->legend()->setAlignment(Qt::AlignRight);
}
QAbstractSeries* stackedBar::convertData(QList<Data> model)
{

    const auto series = new QStackedBarSeries;
    for (const auto& it : model)
    {
        const auto label = it.name + " - " + QString::number(it.percentage, 'f', 3) + "%";
        const auto set = new QBarSet(label);
        set->append(it.percentage);
        series->append(set);
    }
    return series;
}
QChart *stackedBar::getChart()
{
    return charts_;
}
