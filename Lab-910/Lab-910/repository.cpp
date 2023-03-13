#include "repository.h"

Repository::Repository()
{
}

Repository::~Repository()
{
}

void Repository::add(Entitate& p)
{
	this->elems.push_back(p);
}

bool Repository::find(Entitate& p)
{
	std::vector<Entitate>::iterator it = std::find(this->elems.begin(), this->elems.end(), p);
	if (it != this->elems.end())
		return true;
	return false;
}

bool Repository::update(Entitate& pVechi, Entitate& pNou)
{
	std::vector<Entitate>::iterator it = std::find(this->elems.begin(), this->elems.end(), pVechi);
	if (it != this->elems.end())
	{
		*it = pNou;
		return true;
	}
	return false;
}

bool Repository::remove(Entitate& p)
{
	std::vector<Entitate>::iterator it = std::find(this->elems.begin(), this->elems.end(), p);
	if (it != this->elems.end())
	{
		this->elems.erase(it);
		return true;
	}
	return false;
}

std::vector<Entitate> Repository::getAll()
{
	return this->elems;
}

int Repository::getSize()
{
	return this->elems.size();
}

Repository& Repository::operator=(const Repository& r)
{
	if (this != &r)
		this->elems = r.elems;
	return *this;
}

bool Repository::operator==(const Repository& r) const
{
	if (this->elems == r.elems)
		return true;
	return false;
}
