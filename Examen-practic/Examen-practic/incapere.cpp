#include <string.h>
#include "incapere.h"

Incapere::Incapere()
{
	this->timp = 0;
	this->mod = nullptr;
}

Incapere::Incapere(int timp, const char* mod)
{
	this->timp = timp;
	this->mod = new char[strlen(mod) + 1];
	strcpy_s(this->mod, strlen(mod) + 1, mod);
}

Incapere::Incapere(const Incapere& i)
{
	this->timp = i.timp;
	this->mod = new char[strlen(i.mod) + 1];
	strcpy_s(this->mod, strlen(i.mod) + 1, i.mod);
}

Incapere::~Incapere()
{
	if (this->mod != nullptr)
	{
		delete[] this->mod;
		this->mod = nullptr;
	}
}

int Incapere::getTimp()
{
	return this->timp;
}

char* Incapere::getMod()
{
	return this->mod;
}

void Incapere::setTimp(int timp)
{
	this->timp = timp;
}

void Incapere::setMod(const char* mod)
{
	if (this->mod != nullptr)
	{
		delete[] this->mod;
		this->mod = nullptr;
	}
	this->mod = new char[strlen(mod) + 1];
	strcpy_s(this->mod, strlen(mod) + 1, mod);
}

Incapere& Incapere::operator=(const Incapere& i)
{
	if (this != &i)
	{
		this->timp = i.timp;
		if (this->mod != nullptr)
		{
			delete[] this->mod;
			this->mod = nullptr;
		}
		this->mod = new char[strlen(i.mod) + 1];
		strcpy_s(this->mod, strlen(i.mod) + 1, i.mod);
	}
	return *this;
}

bool Incapere::operator==(const Incapere& i) const
{
	return (this->timp == i.timp && strcmp(this->mod, i.mod) == 0);
}

std::istream& operator>>(std::istream& is, Incapere& i)
{
	std::cout << "Introduceti timpul de curatare: ";
	is >> i.timp;
	std::cout << "Introduceti modul de curatare: ";
	i.mod = new char[100];
	std::cin.ignore();
	is.getline(i.mod, 100);
	return is;
}

std::ostream& operator<<(std::ostream& os, Incapere& i)
{
	os << "timp: " << i.timp << ", mod: " << i.mod << std::endl;
	return os;
}
