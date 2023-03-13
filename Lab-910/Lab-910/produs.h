#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>

class Entitate {
private:
	int cod;
	char* nume;
	int pret;
public:
	Entitate();
	Entitate(int cod, const char* nume, int pret);
	Entitate(const Entitate& p);
	~Entitate();
	int getCod();
	char* getNume();
	int getPret();
	void setCod(int cod);
	void setNume(const char* nume);
	void setPret(int pret);
	Entitate& operator=(const Entitate& p);
	bool operator==(const Entitate& p) const;
	friend std::istream& operator>>(std::istream& is, Entitate& p);
	friend std::ostream& operator<<(std::ostream& os, Entitate& p);
};

#endif