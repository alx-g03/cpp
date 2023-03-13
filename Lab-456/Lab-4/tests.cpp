#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <assert.h>
#include "Cerc.h"
#include "functions.h"

using namespace std;

void testCercFaraParametri()
{
	Entitate c;
	assert((c.getCentru() == Punct(0, 0)) && (c.getRaza() == 0));
}

void testCercCuParametri()
{
	Entitate c(Punct(2, 3.5), 22);
	assert((c.getCentru() == Punct(2, 3.5)) && (c.getRaza() == 22));
}

void testSetGet()
{
	Entitate c;
	c.setCentru(Punct(2, 3.5));
	c.setRaza(22);
	assert((c.getCentru() == Punct(2, 3.5)) && (c.getRaza() == 22));
}

void testEqual()
{
	Entitate c1(Punct(2, 3.5), 22), c2(Punct(5, 7), 21), c3(Punct(4.66f, 0.22f), 8);
	c2 = c1;
	c3 = c1;
	assert(c2 == c3);
}

void testLungime()
{
	Entitate c(Punct(2, 3.5), 22);
	assert(c.lungime() == 2 * (float)M_PI * 22);
}

void testArie()
{
	Entitate c(Punct(2, 3.5), 22);
	assert(c.arie() == (float)M_PI * 22 * 22);
}

void testMaxEntitate()
{
	vector<Entitate> x{ Entitate(Punct(1, 2), 9), Entitate(Punct(4, 3), 6), Entitate(Punct(5, 1), 10) };
	assert(maxEntitate(x) == Entitate(Punct(5, 1), 10));
}

void testEsteInPrimulCadran()
{
	assert(esteInPrimulCadran(Entitate(Punct(1, 2), 9)) == false);
	assert(esteInPrimulCadran(Entitate(Punct(1, 2), 0.5)) == true);
	assert(esteInPrimulCadran(Entitate(Punct(5, -5), 4)) == false);
}

void testSecvMaxEgale()
{
	int smax = 1, dmax = 0;
	vector<Entitate> x{ Entitate(Punct(1, 2), 9), Entitate(Punct(1, 2), 9), Entitate(Punct(5, 1), 10) };
	secvMaxEgale(x, smax, dmax);
	assert(smax == 0);
	assert(dmax == 1);
	vector<Entitate> y{ Entitate(Punct(1, 2), 9), Entitate(Punct(6, 2.22f), 4), Entitate(Punct(5, 1), 10), Entitate(Punct(0.5, 2.99f), 3) };
	secvMaxEgale(y, smax, dmax);
	assert(smax == 1);
	assert(dmax == 0);
	vector<Entitate> z{ Entitate(Punct(1, 2), 9), Entitate(Punct(1, 2), 9), Entitate(Punct(5, 1), 10), Entitate(Punct(0.5, 2.99f), 3), Entitate(Punct(0.5, 2.99f), 3), Entitate(Punct(0.5, 2.99f), 3) };
	secvMaxEgale(z, smax, dmax);
	assert(smax == 3);
	assert(dmax == 5);
}

void testAll()
{
	testCercFaraParametri();
	testCercCuParametri();
	testSetGet();
	testEqual();
	testLungime();
	testArie();
	testMaxEntitate();
	testEsteInPrimulCadran();
	testSecvMaxEgale();
	cout << "Toate testele au rulat cu succes!" << endl;
}
