#include "valuta.h"

Valuta::Valuta()
{
	this->valoare = 0;
}

Valuta::Valuta(int valoare)
{
	this->valoare = valoare;
}

Valuta::Valuta(const Valuta& v)
{
	this->valoare = v.valoare;
}

Valuta::~Valuta()
{
}

void Valuta::setValoare(int valoare)
{
	this->valoare = valoare;
}

int Valuta::getValoare()
{
	return this->valoare;
}

Valuta& Valuta::operator=(const Valuta& v)
{
	if (this != &v)
		this->valoare = v.valoare;
	return *this;
}

bool Valuta::operator==(const Valuta& v)
{
	return this->valoare == v.valoare;
}
