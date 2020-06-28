#ifndef TICK_MANAGER_H
#define TICK_MANAGER_H 1

#include <iostream>
#include "Tick.hpp"


class TickManager {
public:
	virtual Tick getNextTick(Tick last_tick) = 0;
	virtual Tick getNextTick() = 0;
	virtual bool hasNextTick() = 0;
};

#endif