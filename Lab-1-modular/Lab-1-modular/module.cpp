#include <iostream>

using namespace std;

int palindrom(int n)
{
	int p = 0;
	while (n)
	{
		p = p * 10 + n % 10;
		n /= 10;
	}
	return p;
}
void readData(int& n)
{
	cout << "n= ";
	cin >> n;
}

void printData(int n)
{
	cout << "Palindromul lui n este " << n;
}
