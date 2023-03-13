#include <iostream>
#include "module.h"

using namespace std;

void printMeniu()
{
	cout << "1. Citirea unei liste de numere intregi de la tastatura" << endl;
	cout << "2. Afisarea unei liste de numere intregi" << endl;
	cout << "3. Afisarea celei mai lungi secvente doar cu numere prime" << endl;
	cout << "4. Afisarea celei mai lungi secvente  cu numere distincte" << endl;
	cout << "x. Inchide" << endl;
}

void runMeniu()
{
	int len = 0, x[100], smax = 1, dmax = 0;
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
			readList(len, x);
			break;
		case '2':
			printList(len, x);
			break;
		case '3':
			secvMaxNrPrime(len, x, smax, dmax);
			printSecvMax(smax, dmax, x);
			break;
		case '4':
			secvMaxNrDistincte(len, x, smax, dmax);
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
