#include "Strategy.hpp"

class RandomBuySellStrategy: public Strategy{
public:
	Trade processTick(Tick t);
};