#include "SmaStrategy.hpp"
#include <iostream>

Trade SmaStrategy::processTick(Tick tick) {

  int quantity = 10;
  int smaDayRange = 5;
  int differenceTolerance = 100;
  Trade::move mv;

  this->tickCount += 1;
  this->totalClosingPrice += tick.close;

  // following block will ensure that if we are making good profit exit
  // position.
  if (this->lastBoughtPrice != 0 && (tick.close - this->lastBoughtPrice) > 10) {
    mv = Trade::SELL;
    if (DEBUG_FLAG) {
      std::cout << "SmaStrategy: Safe SELL SIGNAL generated" << std::endl;
    }
    return Trade(mv, quantity, tick);
  }

  if (this->tickCount >= smaDayRange) {

    long double ma = this->totalClosingPrice / smaDayRange;
    this->tickCount = 0;
    this->totalClosingPrice = 0;

    if (tick.close > ma) {

      this->isPosition = true;
      mv = Trade::BUY;
      this->lastBoughtPrice = tick.close;
      if (DEBUG_FLAG) {
        std::cout << "SmaStrategy: BUY SIGNAL generated" << std::endl;
      }

    } else {

      mv = Trade::PASS;
      if (DEBUG_FLAG) {
        std::cout << "SmaStrategy: PASS SIGNAL generated" << std::endl;
      }
    }

  } else {

    mv = Trade::PASS;
    if (DEBUG_FLAG) {
      std::cout << "SmaStrategy: PASS SIGNAL generated" << std::endl;
    }
  }

  return Trade(mv, quantity, tick);
}