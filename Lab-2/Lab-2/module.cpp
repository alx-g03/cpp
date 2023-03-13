#include <iostream>

using namespace std;

bool isPrime(int n)
{
	if (n < 2)
		return 0;
	if (n < 4)
		return 1;
	for (int d = 2;d <= n / 2;d++)
		if (n % d == 0)
			return 0;
	return 1;
}

bool toateValorileDistincte(int start, int stop, int x[])
{
	for (int i = start;i <= stop - 1;i++)
		for (int j = i + 1;j <= stop;j++)
			if (x[i] == x[j])
				return 0;
	return 1;
}

void readList(int& len, int x[])
{
	cout << "Introduceti lungimea: ";
	cin >> len;
	cout << "Introduceti lista: ";
	for (int i = 0;i < len;i++)
		cin >> x[i];
}

void printList(int len, int x[])
{
	for (int i = 0;i < len;i++)
		cout << x[i] << ' ';
	cout << endl;
}

void printSecvMax(int start, int stop, int x[])
{
	for (int i = start;i <= stop;i++)
		cout << x[i] << ' ';
	cout << endl;
}

void secvMaxNrPrime(int len, int x[], int& smax, int& dmax)
{
	smax = 1, dmax = 0;
	for (int i = 0;i < len;i++)
		if (isPrime(x[i]))
		{
			int j = i;
			while (j + 1 < len && isPrime(x[j + 1]))
				j++;
			if (j - i + 1 > dmax - smax + 1)
				smax = i, dmax = j;
			i = j;
		}
}

void secvMaxNrDistincte(int len, int x[], int& smax, int& dmax)
{
	smax = 1, dmax = 0;
	for (int i = 0;i < len;i++)
	{
		int j = i;
		while (j + 1 < len && toateValorileDistincte(i, j + 1, x))
		{
			j++;
			if (j - i + 1 > dmax - smax + 1)
				smax = i, dmax = j;
		}
		i = j;
	}

}
