# Aku - Toy Backtesting/Trading Engine

Aku is a toy backtesting/trading engine with some very basic interfaces. Its easy to extend aku by providing custom implementation of interfaces.
```bash
Usage:
  Aku v0.0.1 [OPTION...]

  -i, --input arg   Input csv file, will read ticks from here
  -o, --output arg  Output csv file, will output trade / results here
                    (default: output.csv)
  -d, --debug       Enable debugging
  -h, --help        Print usage
 ```

### Key Terms
    - Tick: A standard stock candle.
    - TickManager: Responsible for Fetching Ticks from any source e.g Web/Database
    - TradeManager: Implements Basic operations for your trading exchange/portal.
    - Strategy: Implements processTick()
    
### Your standard Implementation or refer main.cpp.
```cpp
	/* Initialise tick manager*/
   	TickManager * tick_manager;
   	tick_manager = new YourTickManager(input_file);

   	/* Initialise strategy */
   	Strategy * strategy;
   	strategy = new YourCustomStrategy();

   	/* Initialise trade manager */
   	TradeManager * trade_manager;
   	trade_manager = new YourTradeManager(virtual_bank);
   	Tick last_traded_tick;
   	
   	/* Start the core event-loop */
   	while(tick_manager->hasNextTick()){
   		Tick t = tick_manager->getNextTick();
   		last_traded_tick = t;
   		Trade tr = strategy->processTick(t);
   		trade_manager->performTrade(tr);
   	}
```

### Todos

 - Write MORE Tests
 - Clean the code ( as always)
 - Implement more strats
----
MIT

