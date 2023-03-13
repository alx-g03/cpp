#include "service.h"

Service::Service()
{
}

Service::Service(const Repository& r)
{
	this->repo = r;
}

Service::~Service()
{
}

void Service::addTranzactie(int zi, int suma, bool tip, const char* descriere)
{
	Entitate t(zi, suma, tip, descriere);
	this->repo.add(t);
}

bool Service::findTranzactie(int zi, int suma, bool tip, const char* descriere)
{
	Entitate t(zi, suma, tip, descriere);
	return this->repo.find(t);
}

bool Service::updateTranzactie(int ziVeche, int sumaVeche, bool tipVechi, const char* descriereVeche, 
	int ziNoua, int sumaNoua, bool tipNou, const char* descriereNoua)
{
	Entitate tVeche(ziVeche, sumaVeche, tipVechi, descriereVeche);
	Entitate tNoua(ziNoua, sumaNoua, tipNou, descriereNoua);
	return this->repo.update(tVeche, tNoua);
}

bool Service::removeTranzactie(int zi, int suma, bool tip, const char* descriere)
{
	Entitate t(zi, suma, tip, descriere);
	return this->repo.remove(t);
}

Entitate* Service::getAllTransactions()
{
	return this->repo.getAll();
}

int Service::numberOfTransactions()
{
	return this->repo.getSize();
}

void Service::removeAllInADay(int zi)
{
	Entitate* all = this->repo.getAll();
	for (int i = 0;i < repo.getSize();i++)
		if (all[i].getZi() == zi)
		{
			this->repo.remove(all[i]);
			i--;
		}
}

void Service::removeTranzactiiIntervalZile(int ziStart, int ziStop)
{
	Entitate* all = this->repo.getAll();
	for (int i = 0;i < repo.getSize();i++)
		if (all[i].getZi() >= ziStart && all[i].getZi() <= ziStop)
		{
			this->repo.remove(all[i]);
			i--;
		}
}

void Service::removeTranzactiiDupaTip(bool tip)
{
	Entitate* all = this->repo.getAll();
	for (int i = 0;i < repo.getSize();i++)
		if (all[i].getTip() == tip)
		{
			this->repo.remove(all[i]);
			i--;
		}
}

int Service::SoldZi(int zi)
{
	int sumaIn = 0, sumaOut = 0;
	Entitate* all = this->repo.getAll();
	for (int i = 0;i < repo.getSize();i++)
		if (all[i].getZi() == zi)
		{
			if (all[i].getTip() == 1)
				sumaIn += all[i].getSuma();
			else
				sumaOut += all[i].getSuma();
		}
	return (sumaIn - sumaOut);
}

int Service::sumaTip(bool tip)
{
	int sumaTotala = 0;
	Entitate* all = this->repo.getAll();
	for (int i = 0;i < this->repo.getSize();i++)
		if (all[i].getTip() == tip)
			sumaTotala += all[i].getSuma();
	return sumaTotala;
}

Entitate Service::maxTipZi(bool tip, int zi)
{
	Entitate max(0, 0, 0, "");
	Entitate* all = this->repo.getAll();
	for (int i = 0;i < this->repo.getSize();i++)
		if (all[i].getTip() == tip && all[i].getZi() == zi)
			if (max.getSuma() < all[i].getSuma())
				max = all[i];
	return max;
}

std::vector<Entitate> Service::filterType(bool tip)
{
	std::vector<Entitate> rez;
	Entitate* all = this->repo.getAll();
	for (int i = 0;i < this->repo.getSize();i++)
		if (all[i].getTip() == tip)
			rez.push_back(all[i]);
	return rez;
}

std::vector<Entitate> Service::filterTypeLessThanSum(bool tip, int sumaMax)
{
	std::vector<Entitate> rez;
	Entitate* all = this->repo.getAll();
	for (int i = 0;i < this->repo.getSize();i++)
		if (all[i].getTip() == tip && all[i].getSuma() < sumaMax)
			rez.push_back(all[i]);
	return rez;
}
