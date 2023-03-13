#include "repository.h"

Repository::Repository()
{
	this->size = 0;
}

Repository::~Repository()
{
}

void Repository::add(Entitate& t)
{
	this->elems[this->size++] = t;
}

bool Repository::find(Entitate& t)
{
	for (int i = 0;i < this->size;i++)
		if (this->elems[i] == t)
			return true;
	return false;
}

bool Repository::update(Entitate& tVeche, Entitate& tNoua)
{
	for (int i = 0;i < this->size;i++)
		if (this->elems[i] == tVeche)
		{
			this->elems[i] = tNoua;
			return true;
		}
	return false;
}

bool Repository::remove(Entitate& t)
{
	for (int i = 0;i < this->size;i++)
		if (this->elems[i] == t)
		{
			if (i != this->size - 1)
			{
				for (int j = i;j < this->size - 1;j++)
					this->elems[j] = this->elems[j + 1];
				this->size--;
				return true;
			}
			else
			{
				this->size--;
				return true;
			}
		}
	return false;
}

Entitate* Repository::getAll()
{
	return this->elems;
}

int Repository::getSize()
{
	return this->size;
}

Repository& Repository::operator=(const Repository& r)
{
	if (this != &r)
	{
		this->size = r.size;
		for (int i = 0;i < this->size;i++)
			this->elems[i] = r.elems[i];
	}
	return *this;
}

bool Repository::operator==(const Repository& r)
{
	if (this->size != r.size)
		return false;
	for (int i = 0;i < this->size;i++)
		if (!(this->elems[i] == r.elems[i]))
			return false;
	return true;
}
