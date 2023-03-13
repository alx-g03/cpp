#ifndef TRANZACTIE_H
#define TRANZACTIE_H

#include <iostream>

class Entitate {
private:
	int zi;
	int suma;
	bool tip;
	char* descriere;
public:
	Entitate();
	Entitate(int zi, int suma, bool tip, const char* descriere);
	Entitate(const Entitate& t);
	~Entitate();
	int getZi();
	int getSuma();
	bool getTip();
	char* getDescriere();
	void setZi(int zi);
	void setSuma(int suma);
	void setTip(bool tip);
	void setDescriere(const char* descriere);
	Entitate& operator=(const Entitate& t);
	bool operator==(const Entitate& t);
	friend std::istream& operator>>(std::istream& is, Entitate& t);
	friend std::ostream& operator<<(std::ostream& os, Entitate& t);
};

#endif