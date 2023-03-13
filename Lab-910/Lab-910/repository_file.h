#ifndef REPOSITORY_FILE_H
#define REPOSITORY_FILE_H

#include "repository.h"

class RepoFile : public Repository {
private:
	const char* filename;
public:
	RepoFile();
	RepoFile(const char* filename);
	~RepoFile();
	void saveToFile();
	void add(Entitate& p);
	bool find(Entitate& p);
	bool update(Entitate& pVechi, Entitate& pNou);
	bool remove(Entitate& p);
	std::vector<Entitate> getAll();
	int getSize();
};

#endif