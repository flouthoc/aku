#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

void removeCommasfromCurrency(std::string &str){
	str.erase(std::remove(str.begin(), str.end(), ','), str.end());
}

long double stodpre(std::string const &str, std::size_t const p) {
  std::stringstream sstrm;
  sstrm << std::setprecision(p) << std::fixed << str << std::endl;
  
  long double d;
  sstrm >> d;
  
  return d;
}




int main(){
	std::string money = "22,919.150024";
	removeCommasfromCurrency(money);
	long double r_money = std::stold(money);
	r_money *= 2;

	std::string vaAsString = std::to_string(r_money);
	std::cout<<vaAsString<<std::endl;

	long double real_money = stodpre("9992.3293232932", 5);
	real_money = real_money * 2;
	std::string varAsString = std::to_string(real_money);
	std::cout<<varAsString<<std::endl;
	//std::cout << std::fixed;
	//std::cout << std::setprecision(5);
	//std::cout<<real_money<<std::endl;
}