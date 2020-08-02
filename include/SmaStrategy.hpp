#include "Strategy.hpp"

class SmaStrategy: public Strategy {
public:
	//vector<Tick> tickBuffer;
	bool isPosition = false;
	int tickCount;
	long double totalClosingPrice;
	long double lastBoughtPrice;
	Trade processTick(Tick t);
};