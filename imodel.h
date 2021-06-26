#ifndef IMODEL_H
#define IMODEL_H
#include <data.h>
class IModel
{
public:
    IModel()=default;
    virtual void updateModel(QList<Data>)=0;
};

#endif // IMODEL_H
