#include <iostream>
#include <assert.h>
#include "module.h"

using namespace std;

void testSecvMaxNrPrime()
{
	int x[] = { 1,2,3,5,9 }, smax = 1, dmax = 0;
	secvMaxNrPrime(5, x, smax, dmax);
	assert(smax == 1);
	assert(dmax == 3);
	int y[] = { 12,14,22,80,500 };
	secvMaxNrPrime(5, y, smax, dmax);
	assert(smax == 1);
	assert(dmax == 0);
	int z[] = { 1,6,2,3,5,60,3,11,7,23,9 };
	secvMaxNrPrime(11, z, smax, dmax);
	assert(smax == 6);
	assert(dmax == 9);
	int t[] = { 2,3,5,11 };
	secvMaxNrPrime(4, t, smax, dmax);
	assert(smax == 0);
	assert(dmax == 3);
}

void testSecvMaxNrDistincte()
{
	int x[] = { 1,1,2,3,3 }, smax = 1, dmax = 0;
	secvMaxNrDistincte(5, x, smax, dmax);
	assert(smax == 1);
	assert(dmax == 3);
	int y[] = { 12,12,12,12,12 };
	secvMaxNrDistincte(5, y, smax, dmax);
	assert(smax == 1);
	assert(dmax == 0);
	int z[] = { 1,1,1,2,2,3,4,5,5,5 };
	secvMaxNrDistincte(10, z, smax, dmax);
	assert(smax == 4);
	assert(dmax == 7);
	int t[] = { 1,2,3,5,7,7,11,13,9,10,15 };
	secvMaxNrDistincte(11, t, smax, dmax);
	assert(smax == 5);
	assert(dmax == 10);
}

void testAll()
{
	testSecvMaxNrPrime();
	testSecvMaxNrDistincte();
	cout << "Toate testele au rulat cu succes!" << endl;
}
