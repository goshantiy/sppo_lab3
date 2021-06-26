#ifndef STACKEDBAR_H
#define STACKEDBAR_H
#include <QBarSet>
#include <charts.h>
#include <QStackedBarSeries>
#include <QSplineSeries>
class stackedBar:public charts
{
public:
    stackedBar(QWidget*,QList<Data>);
    ~stackedBar()=default;
    virtual QAbstractSeries* convertData(QList<Data>);
    QChart* getChart();
};

#endif // STACKEDBAR_H
