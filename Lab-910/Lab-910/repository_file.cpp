#include <fstream>
#include <string.h>
#include "repository_file.h"

RepoFile::RepoFile() : Repository()
{
	this->filename = nullptr;
}

RepoFile::RepoFile(const char* filename) : Repository()
{
	this->filename = filename;
	std::ifstream f(filename);
	int cod;
	while (f >> cod)
	{
		int pret;
		char* nume = new char[100];
		f.ignore();
		f >> nume >> pret;
		Entitate p(cod, nume, pret);
		Repository::add(p);
		delete[] nume;
	}
	f.close();
}

RepoFile::~RepoFile()
{
	std::fstream f(this->filename);
	if (f.is_open())
		f.close();
}

void RepoFile::saveToFile()
{
	std::ofstream g(this->filename);
	for (auto p : this->getAll())
		g << p.getCod() << ' ' << p.getNume() << ' ' << p.getPret() << std::endl;
	g.close();
}

void RepoFile::add(Entitate& p)
{
	Repository::add(p);
	this->saveToFile();
}

bool RepoFile::find(Entitate& p)
{
	return Repository::find(p);
}

bool RepoFile::update(Entitate& pVechi, Entitate& pNou)
{
	bool rez = Repository::update(pVechi, pNou);
	this->saveToFile();
	return rez;
}

bool RepoFile::remove(Entitate& p)
{
	bool rez = Repository::remove(p);
	this->saveToFile();
	return rez;
}

std::vector<Entitate> RepoFile::getAll()
{
	return Repository::getAll();
}

int RepoFile::getSize()
{
	return Repository::getSize();
}
