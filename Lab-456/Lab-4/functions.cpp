#include <iostream>
#include <vector>
#include "Cerc.h"

using namespace std;

void readEntitate(vector<Entitate>& x)
{
	Entitate c;
	cin >> c;
	x.push_back(c);
}

void printEntitati(vector<Entitate> x)
{
	for (int i = 0;i < x.size();i++)
		cout << x.at(i) << ' ';
	cout << endl;
}

Entitate maxEntitate(vector<Entitate> x)
{
	Entitate max;
	for (int i = 0;i < x.size();i++)
		if (x.at(i) > max)
			max = x.at(i);
	return max;
}

bool esteInPrimulCadran(Entitate c)
{
	Punct centru = c.getCentru();
	return (centru.getX() > 0 && centru.getY() > 0 && c.getRaza() < centru.getX() && c.getRaza() < centru.getY());
}

void printEsteInPrimulCadran(vector<Entitate> x)
{
	for (int i = 0;i < x.size();i++)
		if (esteInPrimulCadran(x.at(i)))
			cout << x.at(i) << ' ';
	cout << endl;
}

bool toateEntitatileEgale(int start, int stop, vector<Entitate> x)
{
	for (int i = start;i <= stop - 1;i++)
		for (int j = i + 1;j <= stop;j++)
			if (!(x.at(i) == x.at(j)))
				return 0;
	return 1;
}

void secvMaxEgale(vector<Entitate> x, int& smax, int& dmax)
{
	smax = 1, dmax = 0;
	for (int i = 0;i < x.size();i++)
	{
		int j = i;
		while (j + 1 < x.size() && toateEntitatileEgale(i, j + 1, x))
		{
			j++;
			if (j - i + 1 > dmax - smax + 1)
				smax = i, dmax = j;
		}
		i = j;
	}
}

void printSecvMax(int start, int stop, vector<Entitate> x)
{
	for (int i = start;i <= stop;i++)
		cout << x.at(i) << ' ';
	cout << endl;
}
