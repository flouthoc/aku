#include "TradeManager.hpp"
#include <iostream>

int TradeManager::performTrade(Trade trade) {
  if (trade.mv == Trade::BUY) {
    this->performBuyInternal(trade);
  }
  if (trade.mv == Trade::SELL) {
    this->performSellInternal(trade);
  }

  return 0;
}

int TradeManager::performBuyInternal(Trade trade) {

  if (this->canBuy(trade)) {

    if (DEBUG_FLAG) {
      std::string trade_log = "Bought - " + std::to_string(trade.quantity) +
                              " at " + std::to_string(trade.tick.close) +
                              " on " + std::to_string(trade.tick.time);
    }

    this->trades.push_back(trade);
    this->quantity += trade.quantity;
    this->performBuy(trade);
    return 1;
  }

  return 0;
}

int TradeManager::performSellInternal(Trade trade) {

  if (this->canSell(trade)) {

    if (DEBUG_FLAG) {
      std::string trade_log = "Sold - " + std::to_string(trade.quantity) +
                              " at " + std::to_string(trade.tick.close) +
                              " on " + std::to_string(trade.tick.time);
    }

    this->trades.push_back(trade);
    this->quantity -= trade.quantity;
    this->performSell(trade);
    return 1;
  }

  return 0;
}

int TradeManager::dumpTrades() {
  std::cout << "Printing all the trades" << std::endl;
  std::cout << std::endl;
  for (auto trade : this->trades) {
    trade.dump();
    std::cout << std::endl;
  }
  std::cout << std::endl;
}