#ifndef TRADE_HPP
#define TRADE_HPP 1

#include <iostream>
#include "Tick.hpp"
#include "Trade.hpp"

class Trade{
public:
	enum move {BUY, SELL, PASS};
	Trade::move mv;
	int quantity;
	Tick tick;
	Trade(Trade::move mv, int quantity, Tick tick){
		this->mv = mv;
		this->quantity = quantity;
		this->tick = tick;
	}
	void dump(){
		std::cout<<"Dumping a trade sequence"<<std::endl;
		std::string trade_move;

		if(this->mv == Trade::BUY)
			trade_move = "BUY";
		else if(this->mv == Trade::SELL)
			trade_move = "SELL";
		else
			trade_move = "PASS";

		std::cout<<"TradeMove - "<<trade_move<<std::endl;
		std::cout<<"Trade quantity - "<<this->quantity<<std::endl;
		std::cout<<"Tick Info -- "<<std::endl;
		this->tick.dump();
		std::cout<<std::endl;

	}

};


#endif