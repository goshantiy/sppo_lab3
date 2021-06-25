#ifndef ISTRATEGY_H
#define ISTRATEGY_H
#include <QString>
#include <QMap>
#include <QDir>
#include <QFileInfo>
#include <iostream>
#include <QTextStream>
#include <data.h>
class IStrategy
{
public:
    explicit IStrategy()=default;
    virtual ~IStrategy()=default;
    virtual QList<Data> calculate(QString &path)=0;

};

#endif // ISTRATEGY_H
