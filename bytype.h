#ifndef BYTYPE_H
#define BYTYPE_H
#include <istrategy.h>
class byType:public IStrategy
{
public:
    byType()=default;
    void calculate(QString& path);
    double filesSize(const QString& path);
    double directorySize(QDir dir);//размер директории
    void setMap(const QMap<QString,double>& first,QMap<QString,double>& second) ;
    void printPercentage(const QMap<QString, double>& filesList);
    QMap<QString,double> getTypePercentage(QMap<QString,double>, double);
    QMap<QString,double> getFilesInfo(const QString&);
};

#endif // BYTYPE_H
