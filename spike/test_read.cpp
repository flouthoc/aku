#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

void parseTickfromString(std::string line){

	std::vector<std::string> tokens;
	std::stringstream check1(line);
	std::string token;
	while(std::getline(check1, token, ',')){
		tokens.push_back(token);
		std::cout<<"Token Found "<<token<<std::endl;
	}
}


int parseDatefromString(std::string line){
	int date;
	line.erase(std::remove(line.begin(), line.end(), '-'),
	 line.end());
	//std::cout<<line<<std::endl;
	return std::stoi(line);
}

int main(){

	//std::ifstream input_file("HDFC2.csv");
	//for(std::string line; std::getline(input_file, line);){
	//	parseTickfromString(line);
	//}

	std::cout<<parseDatefromString("2020-01-13")<<std::endl;

}