#ifndef CERC_H
#define CERC_H

#include <iostream>
#include "Punct.h"

using namespace std;

class Entitate {
private:
	Punct centru;
	float raza;

public:
	Entitate();
	Entitate(Punct centru, float raza);
	Entitate(const Entitate& c);
	~Entitate();
	Punct getCentru();
	float getRaza();
	void setCentru(Punct centru);
	void setRaza(float raza);
	Entitate& operator=(const Entitate& c);
	bool operator>(const Entitate& c);
	bool operator==(const Entitate& c);
	friend istream& operator>>(istream& is, Entitate& c);
	friend ostream& operator<<(ostream& os, Entitate& c);
	float lungime();
	float arie();
};

#endif