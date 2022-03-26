#include <fstream>
#include <iostream>
#include <random>

#include "cxxopts.hpp"
#include "staticmsgs.hpp"

#include "Tick.hpp"
#include "TickManager.hpp"

#include "RandomTickManager.hpp"
#include "YahooFinanceFileTickManager.hpp"

#include "RandomBuySellStrategy.hpp"
#include "Strategy.hpp"

#include "PaperTradeManager.hpp"
#include "TradeManager.hpp"

#include "VirtualBank.hpp"

int main(int argc, char **argv) {

  cxxopts::Options options("Aku v0.0.1",
                           "Aku - Toy Backtesting/Trading Engine");

  /* Everything related to command-line options */

  options.add_options()("i,input", "Input csv file, will read ticks from here",
                        cxxopts::value<std::string>())(
      "o,output", "Output csv file, will output trade / results here",
      cxxopts::value<std::string>()->default_value("output.csv"))(
      "d,debug", "Enable debugging",
      cxxopts::value<bool>()->default_value("false"))("h,help", "Print usage");

  std::string input_file;  // path to input file
  std::string output_file; // path to output file
  auto result = options.parse(argc, argv);

  // print help if help specified
  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    exit(0);
  }

  // set debug mode if specificed
  bool debug = result["debug"].as<bool>();

  // check if input file is specified or not.
  // exit if not specified
  if (result.count("input")) {
    input_file = result["input"].as<std::string>();
  } else {
    std::cout << staticmsgs::noinputfile << std::endl;
    std::cout << options.help() << std::endl;
    exit(0);
  }

  // set path to output file
  output_file = result["output"].as<std::string>();

  if (DEBUG_FLAG) {
    std::cout << staticmsgs::printargs << std::endl;
    std::cout << "Path to input file " << input_file << std::endl;
    std::cout << "Path to output file " << output_file << std::endl;
  }

  /* End everything related to command-line options */

  /* Initialise tick manager*/
  TickManager *tick_manager;
  // tick_manager = new RandomTickManager();
  tick_manager = new YahooFinanceFileTickManager(input_file);

  /* Initialise strategy */
  // seed rand()
  srand((unsigned int)time(NULL));
  Strategy *strategy;
  strategy = new RandomBuySellStrategy();

  /*Initialise a virtual bank*/
  VirtualBank *virtual_bank;
  long double bank_balance = 100000;
  virtual_bank = new VirtualBank(bank_balance);

  /* Initialise trade manager */
  TradeManager *trade_manager;
  trade_manager = new PaperTradeManager(virtual_bank);

  Tick last_traded_tick;
  /* Start the core event-loop */
  while (tick_manager->hasNextTick()) {
    Tick t = tick_manager->getNextTick();
    last_traded_tick = t;
    // t.dump();

    Trade tr = strategy->processTick(t);
    trade_manager->performTrade(tr);
  }

  trade_manager->squareOff(last_traded_tick);
  trade_manager->dumpTrades();

  std::string final_bank_balance =
      std::to_string(virtual_bank->getBankBalance());
  std::string profit_or_loss =
      std::to_string(virtual_bank->getBankBalance() - bank_balance);

  std::cout << "Total Bank Balance: " << final_bank_balance << std::endl;
  std::cout << "Profit or loss: " << profit_or_loss << std::endl;

  return 0;
}
