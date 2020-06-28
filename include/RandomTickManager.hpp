#include <iostream>
#include <cstdlib>
#include <time.h>
#include "TickManager.hpp"

/* Example Tick Manager */

/* Following Manager is only for testing purpose
Do not use this manager in prod */

class RandomTickManager: public TickManager{
public:
	Tick getNextTick(Tick last_tick);
	Tick getNextTick();

private:
	int genRandomInt();
	float genRandomFloat();
};