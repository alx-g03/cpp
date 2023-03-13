#include "service.h"

Service::Service()
{
}

Service::Service(const RepoFile& r, const RepoFileValuta& rv)
{
	this->repo = r;
	this->repoFileValuta = rv;
}

Service::~Service()
{
}

void Service::addProdus(int cod, const char* nume, int pret)
{
	Entitate p(cod, nume, pret);
	this->repo.add(p);
}

bool Service::findProdus(int cod, const char* nume, int pret)
{
	Entitate p(cod, nume, pret);
	return this->repo.find(p);
}

bool Service::updateProdus(int codVechi, const char* numeVechi, int pretVechi, 
	int codNou, const char* numeNou, int pretNou)
{
	Entitate pVechi(codVechi, numeVechi, pretVechi);
	Entitate pNou(codNou, numeNou, pretNou);
	return this->repo.update(pVechi, pNou);
}

bool Service::removeProdus(int cod, const char* nume, int pret)
{
	Entitate p(cod, nume, pret);
	return this->repo.remove(p);
}

std::vector<Entitate> Service::getAll()
{
	return this->repo.getAll();
}

int Service::getSize()
{
	return this->repo.getSize();
}

void Service::removeHigehrThanValue(int pret)
{
	for (Entitate& p : this->repo.getAll())
		if (p.getPret() > pret)
			this->repo.remove(p);
}

void Service::buyAndGetChange(int cod, int suma)
{
}
