#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

double stodpre(std::string const &str, std::size_t const p) {
  std::stringstream sstrm;
  sstrm << std::setprecision(p) << std::fixed << str << std::endl;
  
  double d;
  sstrm >> d;
  
  return d;
}

int main() {
  int p = 5;
  std::cout << std::setprecision(p) << std::fixed << stodpre("9992.3293232932", p) << std::endl;
}