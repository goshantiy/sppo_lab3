#ifndef ISTRATEGY_H
#define ISTRATEGY_H
#include <QString>
#include <QMap>
#include <QDir>
#include <QFileInfo>
#include <iostream>
#include <QTextStream>
class IStrategy
{
public:
    explicit IStrategy()=default;
    virtual ~IStrategy()=default;
    virtual void explorer(QString &path)=0;
public:

};

#endif // ISTRATEGY_H
