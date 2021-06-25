#include "controlstrategy.h"
#include <istrategy.h>
controlStrategy::controlStrategy(IStrategy* strategy):strategy_(strategy)
{

}
controlStrategy::~controlStrategy()
{
    delete this->strategy_;
}
void controlStrategy::setStrategy(IStrategy* strategy)
{
       delete strategy_;
       strategy_ = strategy;
}

QList<Data> controlStrategy::doStrategy(QString &path)
{
    return strategy_->calculate(path);
}
