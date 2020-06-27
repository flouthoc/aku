#include <iostream>
#include <fstream>

#include "cxxopts.hpp"
#include "staticmsgs.hpp"


#include "RandomTickManager.hpp"
#include "TickManager.hpp"
#include "Tick.hpp"

#include "YahooFinanceFileTickManager.hpp"


int main(int argc, char** argv){

	cxxopts::Options options("Aku v0.0.1", "Backtesting Engine");
	
	/* Everything related to command-line options */

	options.add_options()
        ("b,bar", "Param bar", cxxopts::value<std::string>())
        ("i,input", "Input csv file, will read ticks from here", cxxopts::value<std::string>())
        ("o,output", "Output csv file, will output trade / results here", 
        	cxxopts::value<std::string>()->default_value("output.csv"))
        ("d,debug", "Enable debugging", cxxopts::value<bool>()->default_value("false"))
        ("f,foo", "Param foo", cxxopts::value<int>()->default_value("10"))
        ("h,help", "Print usage")
    ;


    std::string input_file; //path to input file
    std::string output_file; //path to output file
    auto result = options.parse(argc, argv);

    //print help if help specified
    if (result.count("help"))
    {
      std::cout << options.help() << std::endl;
      exit(0);
    }

    //set debug mode if specificed
    bool debug = result["debug"].as<bool>();

   	//check if input file is specified or not.
   	//exit if not specified
   	if(result.count("input")){
   		input_file = result["input"].as<std::string>();
   	}else{
   		std::cout << staticmsgs::noinputfile << std::endl;
   		std::cout << options.help() <<std::endl;
   		exit(0);
   	}

   	//set path to output file
   	output_file = result["output"].as<std::string>();


   	if(DEBUG_FLAG){
   		std::cout<<staticmsgs::printargs<<std::endl;
   		std::cout<<"Path to input file "<<input_file<<std::endl;
   		std::cout<<"Path to output file "<<output_file<<std::endl;
   	} 

	/* End everything related to command-line options */

   	/* Initialise tick manager*/
   	TickManager * tick_manager;
   	//tick_manager = new RandomTickManager();
   	tick_manager = new YahooFinanceFileTickManager(input_file);

   	/* Start the core event-loop */
   	Tick t = tick_manager->getNextTick();
   	t.dump_tick();



	return 0;
}