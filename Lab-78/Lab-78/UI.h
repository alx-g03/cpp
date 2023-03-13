#ifndef UI_H
#define UI_H

#include "service.h"

class UI {
private:
	Service service;
	void addTranzactie();
	void findTranzactie();
	void updateTranzactie();
	void removeTranzactie();
	void getAllTransactions();
	void numberOfTransactions();
	void removeAllInADay();
	void removeTranzactiiIntervalZile();
	void removeTranzactiiDupaTip();
	void printTranzactiiTip();
	void printGreaterThanSum();
	void printEqualToSum();
	void printSoldZi();
	void printSumaTip();
	void printMaxTipZi();
	void printFilterType();
	void printFilterTypeLessThanSum();
public:
	UI();
	UI(Service& s);
	~UI();
	void runMeniu();
};

#endif