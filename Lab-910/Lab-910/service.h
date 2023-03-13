#ifndef SERVICE_H
#define SERVICE_H

#include "repository_file.h"
#include "repository_file_valuta.h"

class Service {
private:
	RepoFile repo;
	RepoFileValuta repoFileValuta;
public:
	Service();
	Service(const RepoFile& r, const RepoFileValuta& rv);
	~Service();
	void addProdus(int cod, const char* nume, int pret);
	bool findProdus(int cod, const char* nume, int pret);
	bool updateProdus(int codVechi, const char* numeVechi, int pretVechi, 
		int codNou, const char* numeNou, int pretNou);
	bool removeProdus(int cod, const char* nume, int pret);
	std::vector<Entitate> getAll();
	int getSize();
	void removeHigehrThanValue(int pret);
	void buyAndGetChange(int cod, int suma);
};

#endif