#include "RandomTickManager.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

int RandomTickManager::genRandomInt(){
	srand (time(NULL));
	return rand();
}

float RandomTickManager::genRandomFloat(){
	srand (time(NULL));
	float r = static_cast <float> (rand());
	return r;
}

Tick RandomTickManager::getNextTick(Tick last_tick){
	Tick random_tick;
	random_tick.open = genRandomFloat();
	random_tick.close = genRandomFloat();
	random_tick.high = genRandomFloat();
	random_tick.adjust_close = genRandomFloat();
	random_tick.volume = genRandomInt();
	random_tick.time = genRandomInt();
	return random_tick;
}

Tick RandomTickManager::getNextTick(){
	Tick random_tick;
	random_tick.open = genRandomFloat();
	random_tick.close = genRandomFloat();
	random_tick.high = genRandomFloat();
	random_tick.adjust_close = genRandomFloat();
	random_tick.volume = genRandomInt();
	random_tick.time = genRandomInt();
	return random_tick;
}
