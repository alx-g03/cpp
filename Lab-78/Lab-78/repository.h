#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "tranzactie.h"

class Repository {
private:
	int size;
	Entitate elems[100];
public:
	Repository();
	~Repository();
	void add(Entitate& t);
	bool find(Entitate& t);
	bool update(Entitate& tVeche, Entitate& tNoua);
	bool remove(Entitate& t);
	Entitate* getAll();
	int getSize();
	Repository& operator=(const Repository& r);
	bool operator==(const Repository& r);
};

#endif