#ifndef REPOSITORY_FILE_VALUTA
#define REPOSITORY_FILE_VALUTA

#include <vector>
#include "valuta.h"

class RepoFileValuta {
private:
	const char* filename;
	std::vector<Valuta> valute;
public:
	RepoFileValuta();
	RepoFileValuta(const char* filename);
	~RepoFileValuta();
	void saveToFile();
	void add(Valuta& v);
	bool find(Valuta& v);
	bool update(Valuta& vVeche, Valuta& vNoua);
	bool remove(Valuta& v);
	std::vector<Valuta> getAll();
	int getSize();
};

#endif