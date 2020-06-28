#ifndef VIRTUAL_BANK_HPP
#define VIRTUAL_BANK_HPP 1

class VirtualBank{
public:
	long double totalBalance;
	bool bankCredit(long double);
	bool bankDebit(long double);
	bool bankCanDebit(long double);
	VirtualBank(long double);
	long double getBankBalance();
};

#endif