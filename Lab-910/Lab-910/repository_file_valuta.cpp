#include <fstream>
#include "repository_file_valuta.h"

RepoFileValuta::RepoFileValuta()
{
	this->filename = nullptr;
}

RepoFileValuta::RepoFileValuta(const char* filename)
{
	this->filename = filename;
	std::ifstream f(filename);
	int valoare;
	while (f >> valoare)
	{
		Valuta v(valoare);
		this->valute.push_back(v);
	}
	f.close();
}

RepoFileValuta::~RepoFileValuta()
{
}

void RepoFileValuta::saveToFile()
{
	std::ofstream g(this->filename);
	for (auto v : this->getAll())
		g << v.getValoare() << std::endl;
	g.close();
}

void RepoFileValuta::add(Valuta& v)
{
	this->valute.push_back(v);
	this->saveToFile();
}

bool RepoFileValuta::find(Valuta& v)
{
	std::vector<Valuta>::iterator it = std::find(this->valute.begin(), this->valute.end(), v);
	if (it != this->valute.end())
		return true;
	return false;
}

bool RepoFileValuta::update(Valuta& vVeche, Valuta& vNoua)
{
	std::vector<Valuta>::iterator it = std::find(this->valute.begin(), this->valute.end(), vVeche);
	if (it != this->valute.end())
	{
		*it = vNoua;
		return true;
	}
	return false;
}

bool RepoFileValuta::remove(Valuta& v)
{
	std::vector<Valuta>::iterator it = std::find(this->valute.begin(), this->valute.end(), v);
	if (it != this->valute.end())
	{
		this->valute.erase(it);
		return true;
	}
	return false;
}

std::vector<Valuta> RepoFileValuta::getAll()
{
	return this->valute;
}

int RepoFileValuta::getSize()
{
	return this->valute.size();
}
