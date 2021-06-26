#ifndef CHARTS_H
#define CHARTS_H
#include <QChart>
#include <imodel.h>
#include <data.h>
using namespace QtCharts;
class charts:public IModel
{
public:
    charts();
    virtual void updateModel(QList<Data>);
    virtual QAbstractSeries* convertData(QList<Data>)=0;
    virtual void updateChart(QAbstractSeries*);
protected:
    QChart* charts_;

};

#endif // CHARTS_H
