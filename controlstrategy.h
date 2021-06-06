#ifndef CONTROLSTRATEGY_H
#define CONTROLSTRATEGY_H
#include <istrategy.h>
class controlStrategy
{
public:
    controlStrategy(IStrategy* strategy = nullptr);
    ~controlStrategy();
    void setStrategy(IStrategy* strategy);
    void doStrategy(QString& path);
private:
    IStrategy* strategy_;
};

#endif // CONTROLSTRATEGY_H
