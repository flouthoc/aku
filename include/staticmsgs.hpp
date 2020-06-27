#include <iostream>

class staticmsgs{
public:
	static std::string noinputfile;
	static std::string printargs;
};


std::string staticmsgs::noinputfile = "No Input file specified. Input file is a mandatory arugment";
std::string staticmsgs::printargs = "Printing all arugments ...";