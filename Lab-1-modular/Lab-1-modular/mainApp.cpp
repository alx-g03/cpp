#include <iostream>
#include "module.h"
#include "tests.h"

using namespace std;

int main()
{
	int n, p;
	testPalindrom();
	readData(n);
	p = palindrom(n);
	printData(p);
	return 0;
}
