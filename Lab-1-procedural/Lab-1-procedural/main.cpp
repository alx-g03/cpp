#include <iostream>

using namespace std;

int main()
{
	int n, p = 0;
	cout << "n = ";
	cin >> n;
	while (n)
	{
		p = p * 10 + n % 10;
		n /= 10;
	}
	cout << "Palindromul lui n este " << p;
	return 0;
}
