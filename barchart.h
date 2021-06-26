#ifndef BARCHART_H
#define BARCHART_H
#include <charts.h>
#include <QBarSeries>
#include <QBarSet>
class barChart:public charts
{
public:
    barChart(QWidget*,QList<Data>);
    ~barChart()=default;
    virtual QAbstractSeries* convertData(QList<Data>);
    QChart* getChart();
};

#endif // BARCHART_H
