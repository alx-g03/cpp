#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "Cerc.h"

void readEntitate(vector<Entitate>& x);

void printEntitati(vector<Entitate> x);

Entitate maxEntitate(vector<Entitate> x);

bool esteInPrimulCadran(Entitate c);

void printEsteInPrimulCadran(vector<Entitate> x);

bool toateEntitatileEgale(int start, int stop, vector<Entitate> x);

void secvMaxEgale(vector<Entitate> x, int& smax, int& dmax);

void printSecvMax(int start, int stop, vector<Entitate> x);

#endif