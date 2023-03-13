#include <string.h>
#include "produs.h"

Entitate::Entitate()
{
	this->cod = 0;
	this->nume = nullptr;
	this->pret = 0;
}

Entitate::Entitate(int cod, const char* nume, int pret)
{
	this->cod = cod;
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->pret = pret;
}

Entitate::Entitate(const Entitate& p)
{
	this->cod = p.cod;
	this->nume = new char[strlen(p.nume) + 1];
	strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
	this->pret = p.pret;
}

Entitate::~Entitate()
{
	if (this->nume != nullptr)
	{
		delete[] this->nume;
		this->nume = nullptr;
	}
}

int Entitate::getCod()
{
	return this->cod;
}

char* Entitate::getNume()
{
	return this->nume;
}

int Entitate::getPret()
{
	return this->pret;
}

void Entitate::setCod(int cod)
{
	this->cod = cod;
}

void Entitate::setNume(const char* nume)
{
	if (this->nume != nullptr)
	{
		delete[] this->nume;
		this->nume = nullptr;
	}
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}

void Entitate::setPret(int pret)
{
	this->pret = pret;
}

Entitate& Entitate::operator=(const Entitate& p)
{
	if (this != &p)
	{
		this->cod = p.cod;
		if (this->nume != nullptr)
		{
			delete[] this->nume;
			this->nume = nullptr;
		}
		this->nume = new char[strlen(p.nume) + 1];
		strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
		this->pret = p.pret;
	}
	return *this;
}

bool Entitate::operator==(const Entitate& p) const
{
	return (this->cod == p.cod && strcmp(this->nume, p.nume) == 0 && this->pret == p.pret);
}

std::istream& operator>>(std::istream& is, Entitate& p)
{
	std::cout << "Introduceti codul produsului: ";
	is >> p.cod;
	std::cout << "Introduceti numele produsului: ";
	p.nume = new char[100];
	std::cin.ignore();
	is.getline(p.nume, 100);
	std::cout << "Introduceti pretul produsului: ";
	is >> p.pret;
	return is;
}

std::ostream& operator<<(std::ostream& os, Entitate& p)
{
	os << "cod: " << p.cod << ", nume: " << p.nume << ", pret: " << p.pret << std::endl;
	return os;
}
