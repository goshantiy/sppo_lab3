#ifndef PIECHART_H
#define PIECHART_H
#include <charts.h>
#include <QPieSeries>
#include <QPieSlice>
#include <QBarSet>
class pieChart:public charts
{
public:
    pieChart(QWidget*, QList<Data>);
    ~pieChart()=default;
    virtual QAbstractSeries* convertData(QList<Data>);
    QChart* getChart();
};

#endif // PIECHART_H
