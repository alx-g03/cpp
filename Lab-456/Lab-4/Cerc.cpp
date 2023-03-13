#define _USE_MATH_DEFINES
#include <math.h>
#include "Cerc.h"

Entitate::Entitate()
{
	this->centru = Punct(0, 0);
	this->raza = 0;
}

Entitate::Entitate(Punct centru, float raza)
{
	this->centru = centru;
	this->raza = raza;
}

Entitate::Entitate(const Entitate& c)
{
	this->centru = c.centru;
	this->raza = c.raza;
}

Entitate::~Entitate()
{
}

Punct Entitate::getCentru()
{
	return this->centru;
}

float Entitate::getRaza()
{
	return this->raza;
}

void Entitate::setCentru(Punct centru)
{
	this->centru = centru;
}

void Entitate::setRaza(float raza)
{
	this->raza = raza;
}

Entitate& Entitate::operator=(const Entitate& c)
{
	if (this != &c)
	{
		this->centru = c.centru;
		this->raza = c.raza;
	}
	return *this;
}

bool Entitate::operator>(const Entitate& c)
{
	return (this->raza > c.raza);
}

bool Entitate::operator==(const Entitate& c)
{
	return (this->centru == c.centru && this->raza == c.raza);
}

istream& operator>>(istream& is, Entitate& c)
{
	cout << "coordonatele centrului:" << endl;
	is >> c.centru;
	cout << "raza = ";
	is >> c.raza;
	return is;
}

ostream& operator<<(ostream& os, Entitate& c)
{
	os << "centru: " << c.centru << ", raza: " << c.raza << endl;
	return os;
}

float Entitate::lungime()
{
	return 2 * (float)M_PI * this->raza;
}

float Entitate::arie()
{
	return (float)M_PI * this->raza * this->raza;
}
