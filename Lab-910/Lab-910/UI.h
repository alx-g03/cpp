#ifndef UI_H
#define UI_H

#include "service.h"

class UI {
private:
	Service service;
	void addProdus();
	void findProdus();
	void updateProdus();
	void removeProdus();
	void printAll();
	void printSize();
	void removeHigehrThanValue();
	void buyAndGetChange();
public:
	UI();
	UI(Service& s);
	~UI();
	void runMeniu();
};

#endif