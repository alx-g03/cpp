#ifndef INCAPERE_H
#define INCAPERE_H

#include <iostream>

class Incapere {
private:
	int timp;
	char* mod;
public:
	Incapere();
	Incapere(int timp, const char* mod);
	Incapere(const Incapere& i);
	~Incapere();
	int getTimp();
	char* getMod();
	void setTimp(int timp);
	void setMod(const char* mod);
	Incapere& operator=(const Incapere& i);
	bool operator==(const Incapere& i) const;
	friend std::istream& operator>>(std::istream& is, Incapere& i);
	friend std::ostream& operator<<(std::ostream& os, Incapere& i);
};

#endif