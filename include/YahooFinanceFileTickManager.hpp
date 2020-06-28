#include <iostream>
#include <vector>
#include "TickManager.hpp"
#include "Tick.hpp"

class YahooFinanceFileTickManager: public TickManager{
public:
	YahooFinanceFileTickManager(std::string file_path);
	Tick getNextTick(Tick last_tick);
	Tick getNextTick();
	int tick_counter;
	std::vector<Tick> tick_store;
	Tick parseTickfromString(std::string line);
	long int parseDatefromString(std::string date);
	bool hasNextTick();

};