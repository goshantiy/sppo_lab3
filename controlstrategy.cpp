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
    delete this->strategy_;
    strategy_ = strategy;
}

void controlStrategy::doStrategy(QString &path)
{
    strategy_->calculate(path);
}
