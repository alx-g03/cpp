#ifndef SERVICE_H
#define SERVICE_H

#include <vector>
#include "repository.h"

class Service {
private:
	Repository repo;
public:
	Service();
	Service(const Repository& r);
	~Service();
	void addTranzactie(int zi, int suma, bool tip, const char* descriere);
	bool findTranzactie(int zi, int suma, bool tip, const char* descriere);
	bool updateTranzactie(int ziVeche, int sumaVeche, bool tipVechi, const char* descriereVeche, 
		int ziNoua, int sumaNoua, bool tipNou, const char* descriereNoua);
	bool removeTranzactie(int zi, int suma, bool tip, const char* descriere);
	Entitate* getAllTransactions();
	int numberOfTransactions();
	void removeAllInADay(int zi);
	void removeTranzactiiIntervalZile(int ziStart, int ziStop);
	void removeTranzactiiDupaTip(bool tip);
	int SoldZi(int zi);
	int sumaTip(bool tip);
	Entitate maxTipZi(bool tip, int zi);
	std::vector<Entitate> filterType(bool tip);
	std::vector<Entitate> filterTypeLessThanSum(bool tip, int sumaMax);
};

#endif