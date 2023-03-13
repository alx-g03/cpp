#include <string.h>
#include "tranzactie.h"

Entitate::Entitate()
{
	this->zi = 0;
	this->suma = 0;
	this->tip = 0;
	this->descriere = nullptr;
}

Entitate::Entitate(int zi, int suma, bool tip, const char* descriere)
{
	this->zi = zi;
	this->suma = suma;
	this->tip = tip;
	this->descriere = new char[strlen(descriere) + 1];
	strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
}

Entitate::Entitate(const Entitate& t)
{
	this->zi = t.zi;
	this->suma = t.suma;
	this->tip = t.tip;
	this->descriere = new char[strlen(t.descriere) + 1];
	strcpy_s(this->descriere, strlen(t.descriere) + 1, t.descriere);
}

Entitate::~Entitate()
{
	if (this->descriere != nullptr)
	{
		delete[] this->descriere;
		this->descriere = nullptr;
	}
}

int Entitate::getZi()
{
	return this->zi;
}

int Entitate::getSuma()
{
	return this->suma;
}

bool Entitate::getTip()
{
	return this->tip;
}

char* Entitate::getDescriere()
{
	return this->descriere;
}

void Entitate::setZi(int zi)
{
	this->zi = zi;
}

void Entitate::setSuma(int suma)
{
	this->suma = suma;
}

void Entitate::setTip(bool tip)
{
	this->tip = tip;
}

void Entitate::setDescriere(const char* descriere)
{
	if (this->descriere != nullptr)
	{
		delete[] this->descriere;
		this->descriere = nullptr;
	}
	this->descriere = new char[strlen(descriere) + 1];
	strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
}

Entitate& Entitate::operator=(const Entitate& t)
{
	if (this != &t)
	{
		this->zi = t.zi;
		this->suma = t.suma;
		this->tip = t.tip;
		if (this->descriere != nullptr)
		{
			delete[] this->descriere;
			this->descriere = nullptr;
		}
		this->descriere = new char[strlen(t.descriere) + 1];
		strcpy_s(this->descriere, strlen(t.descriere) + 1, t.descriere);
	}
	return *this;
}

bool Entitate::operator==(const Entitate& t)
{
	return (this->zi == t.zi && this->suma == t.suma && this->tip == t.tip && strcmp(this->descriere, t.descriere) == 0);
}

std::istream& operator>>(std::istream& is, Entitate& t)
{
	std::cout << "Introduceti ziua tranzactiei: ";
	is >> t.zi;
	std::cout << "Introduceti suma de bani: ";
	is >> t.suma;
	std::cin.ignore();
	char* tip = new char[100];
	bool isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul tranzactiei (in/out): ";
		std::cin.getline(tip, 100);
		if (strcmp(tip, "in") == 0)
		{
			t.tip = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tip, "out") == 0)
			{
				t.tip = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	delete[] tip;
	t.descriere = new char[100];
	std::cout << "Introduceti descrierea tranzactiei: ";
	is.getline(t.descriere, 100);
	return is;
}

std::ostream& operator<<(std::ostream& os, Entitate& t)
{
	os << "zi: " << t.zi << ", suma: " << t.suma << ", tip: ";
	if (t.tip == 1)
		os << "in";
	else
		os << "out";
	os<< ", descriere: " << t.descriere << std::endl;
	return os;
}
