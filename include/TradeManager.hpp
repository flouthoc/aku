#ifndef TRADE_MANAGER_H
#define TRADE_MANAGER_H 1

#include <vector>

#include "Tick.hpp"
#include "Trade.hpp"

class TradeManager{
public:
	int quantity;
	std::vector<Trade> trades;
	enum move {BUY, SELL, PASS};
	int performTrade(Trade trade);

	virtual void performBuy(Trade trade) = 0;
	virtual void performSell(Trade trade) = 0;
	virtual bool canBuy(Trade trade) = 0;
	virtual bool canSell(Trade trade) = 0;
	virtual bool squareOff(Tick last_tick) = 0;

	int performBuyInternal(Trade trade);
	int performSellInternal(Trade trade);
	void dumpTrades();

};


#endif