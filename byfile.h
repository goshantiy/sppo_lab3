#ifndef BYFILE_H
#define BYFILE_H
#include <istrategy.h>
class byFile:public IStrategy
{
public:
    QList<Data> calculate(QString& path);
    explicit byFile()=default;
    virtual ~byFile()=default;
    double filesSize(const QString& path);
    double directorySize(QDir dir);//размер директории
    void printPercentage(const QMap<QString, double>& filesList);
    QMap<QString,double> getFilesInfo(QString& path);
    QMap<QString,double> getPercentage(const QMap<QString,double> list,double dirSize);
};

#endif // BYFILE_H
