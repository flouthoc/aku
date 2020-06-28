#ifndef STRATEGY_HPP
#define STRATEGY_HPP 1

#include "TradeManager.hpp"

class Strategy{
public:
	virtual Trade processTick(Tick t) = 0;
};


#endif