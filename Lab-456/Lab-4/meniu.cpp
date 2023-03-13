#include <iostream>
#include <vector>
#include "Cerc.h"
#include "functions.h"

using namespace std;

void printMeniu()
{
	cout << "1. Introducerea informatiilor despre mai multe entitati si salvarea lor intr-un sir" << endl;
	cout << "2. Afisarea informatiilor despre toate entitatile" << endl;
	cout << "3. Determinarea celei mai mari entitati" << endl;
	cout << "4. Identificarea entitatilor situate complet in cadranul 1 de pe cercul geometric" << endl;
	cout << "5. Identificarea celei mai lungi secvente de entitati egale" << endl;
	cout << "x. Inchide" << endl;
}

void runMeniu()
{
	vector<Entitate> x;
	Entitate max;
	int smax = 1, dmax = 0;
	char optiune;
	bool isRunning = 1;
	while (isRunning)
	{
		printMeniu();
		cout << "Alegeti o optiune: ";
		cin >> optiune;
		switch (optiune)
		{
		case '1':
			readEntitate(x);
			break;
		case '2':
			printEntitati(x);
			break;
		case '3':
			max = maxEntitate(x);
			cout << max << endl;
			break;
		case '4':
			printEsteInPrimulCadran(x);
			break;
		case '5':
			secvMaxEgale(x, smax, dmax);
			printSecvMax(smax, dmax, x);
			break;
		case 'x':
			isRunning = 0;
			break;
		default:
			cout << "Optiune invalida!" << endl;
		}
	}
}
