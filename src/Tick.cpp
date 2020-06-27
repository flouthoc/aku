#include <iostream>
#include "Tick.hpp"


void Tick::dump_tick(){

	std::cout<<"Dumping tick values"<<std::endl;
	std::cout<<"Open - "<<this->open<<std::endl;
	std::cout<<"Close - "<<this->close<<std::endl;
	std::cout<<"Low - "<<this->low<<std::endl;
	std::cout<<"High - "<<this->high<<std::endl;
	std::cout<<"Adjust Close - "<<this->adjust_close<<std::endl;
	std::cout<<"Volume - "<<this->volume<<std::endl;
	std::cout<<"Timestamp -"<<this->time<<std::endl;
	std::cout<<std::endl;
}