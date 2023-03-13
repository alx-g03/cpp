#ifndef PRODUS_VALIDATOR_H
#define PRODUS_VALIDATOR_H

#include <vector>
#include "produs.h"
#include "exception.h"

class ProdusValidator {
public:
	ProdusValidator() = default;
	~ProdusValidator() = default;
	std::vector<Exception> validate(Entitate* p);
};

inline std::vector<Exception> ProdusValidator::validate(Entitate* p)
{
	std::vector<Exception> exceptii;
	if (p->getCod() < 0)
		exceptii.push_back(Exception("Codul produsului nu poate fi negativ!"));
	if (p->getPret() <= 0)
		exceptii.push_back(Exception("Pretul unui produs trebuie sa fie un numar intreg nenul!"));
	return exceptii;
}

#endif