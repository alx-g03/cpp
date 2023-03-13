#include "Punct.h"

Punct::Punct()
{
	this->x = 0;
	this->y = 0;
}

Punct::Punct(float x, float y)
{
	this->x = x;
	this->y = y;
}

Punct::Punct(const Punct& p)
{
	this->x = p.x;
	this->y = p.y;
}

Punct::~Punct()
{
}

float Punct::getX()
{
	return this->x;
}

float Punct::getY()
{
	return this->y;
}

void Punct::setX(float x)
{
	this->x = x;
}

void Punct::setY(float y)
{
	this->y = y;
}

Punct& Punct::operator=(const Punct& p)
{
	if (this != &p)
	{
		this->x = p.x;
		this->y = p.y;
	}
	return *this;
}

bool Punct::operator==(const Punct& p)
{
	return (this->x == p.x && this->y == p.y);
}

istream& operator>>(istream& is, Punct& p)
{
	cout << "x = ";
	is >> p.x;
	cout << "y = ";
	is >> p.y;
	return is;
}

ostream& operator<<(ostream& os, Punct& p)
{
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}
