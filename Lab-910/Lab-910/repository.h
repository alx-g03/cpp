#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include "produs.h"

class Repository {
private:
	std::vector<Entitate> elems;
public:
	Repository();
	~Repository();
	void add(Entitate& p);
	bool find(Entitate& p);
	bool update(Entitate& pVechi, Entitate& pNou);
	bool remove(Entitate& p);
	std::vector<Entitate> getAll();
	int getSize();
	Repository& operator=(const Repository& r);
	bool operator==(const Repository& r) const;
};

#endif