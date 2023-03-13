#include <iostream>
#include <assert.h>
#include "module.h"

using namespace std;

void testPalindrom()
{
	assert(palindrom(0) == 0);
	assert(palindrom(123) == 321);
	assert(palindrom(22) == 22);
	cout << "Toate testele au rulat cu succes!" << endl;
}
