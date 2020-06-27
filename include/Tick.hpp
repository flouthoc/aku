#ifndef TICK_H
#define TICK_H 1

class Tick{
public:

	float open;
	float low;
	float close;
	float high;
	float adjust_close;
	float volume;
	int time;

	void dump_tick();
};



#endif

