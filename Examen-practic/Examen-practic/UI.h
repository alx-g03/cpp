#ifndef UI_H
#define UI_H

#include "service.h"

class UI {
private:
	Service service;
	void removeIncapere();
	void printAll();
public:
	UI();
	UI(Service& s);
	~UI();
	void runMeniu();
};

#endif