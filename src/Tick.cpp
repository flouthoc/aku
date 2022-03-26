#include "Tick.hpp"
#include <iostream>

void Tick::dump() {

  std::cout << "Dumping tick values" << std::endl;
  std::cout << "Timestamp - " << this->time << std::endl;
  std::cout << "Open - " << std::to_string(this->open) << std::endl;
  std::cout << "High - " << std::to_string(this->high) << std::endl;
  std::cout << "Low - " << std::to_string(this->low) << std::endl;
  std::cout << "Close - " << std::to_string(this->close) << std::endl;
  std::cout << "Adjust Close - " << std::to_string(this->adjust_close)
            << std::endl;
  std::cout << "Volume - " << this->volume << std::endl;

  std::cout << std::endl;
}