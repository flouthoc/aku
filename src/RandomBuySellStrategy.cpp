#include "RandomBuySellStrategy.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

Trade RandomBuySellStrategy::processTick(Tick tick) {

  static std::random_device rd;
  static std::mt19937 mt(rd());
  int randomMove;
  int max = 3;
  int min = 1;
  int quantity = 10;
  Trade::move mv;
  // srand((unsigned int)time(NULL));
  // randomMove = min + (rand() % static_cast<int>(max - min + 1));
  std::uniform_int_distribution<int> dist(1, 3);
  randomMove = dist(mt);

  if (randomMove == 1) {
    mv = Trade::BUY;
    if (DEBUG_FLAG) {
      std::cout << "RandomBuySellStrategy: BUY SIGNAL generated" << std::endl;
    }
  }

  if (randomMove == 2) {
    mv = Trade::SELL;
    if (DEBUG_FLAG) {
      std::cout << "RandomBuySellStrategy: SELL SIGNAL generated" << std::endl;
    }
  }

  if (randomMove == 3) {
    mv = Trade::PASS;
    if (DEBUG_FLAG) {
      std::cout << "RandomBuySellStrategy: PASS SIGNAL generated" << std::endl;
    }
  }

  // mv = Trade::BUY;

  return Trade(mv, quantity, tick);
}