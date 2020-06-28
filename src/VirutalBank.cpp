#include <iostream>
#include "VirtualBank.hpp"

VirtualBank::VirtualBank(long double startingBalance){
	this->totalBalance = startingBalance;
}

bool VirtualBank::bankCredit(long double amount){
	this->totalBalance += amount;
	return true;
}

bool VirtualBank::bankCanDebit(long double amount){
	
	if(this->totalBalance >= amount){
		return true;
	}

	return false;	
}

bool VirtualBank::bankDebit(long double amount){

	if(this->totalBalance >= amount){
		this->totalBalance -= amount;
		return true;
	}

	return false;
}

long double VirtualBank::getBankBalance(){
	return this->totalBalance;
}