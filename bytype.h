#ifndef BYTYPE_H
#define BYTYPE_H
#include <istrategy.h>
class byType:public IStrategy
{
public:
    byType()=default;
    void explorer(QString& path);
    double filesSize(const QString& path);
    double directorySize(QDir dir);//размер директории
    void printPercentage(const QMap<QString, double>& filesList);
protected:
    QMap<QString,double> getTypePercentage(QMap<QString,double>, double);
    QMap<QString,double> getFilesInfo(QString&);
};

#endif // BYTYPE_H
