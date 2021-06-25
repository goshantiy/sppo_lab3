#ifndef DATA_H
#define DATA_H
#include <QString>
class Data
{
   public:
   Data(const QString& Name,const double& Size ,const double& Percentage)
   :name(Name),size(Size),percentage(Percentage){};
   QString name;
   double size, percentage;
};

#endif // DATA_H
