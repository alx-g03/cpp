#ifndef PUNCT_H
#define PUNCT_H

#include <iostream>

using namespace std;

class Punct {
private:
	float x;
	float y;

public:
	Punct();
	Punct(float x, float y);
	Punct(const Punct& p);
	~Punct();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	Punct& operator=(const Punct& p);
	bool operator==(const Punct& p);
	friend istream& operator>>(istream& is, Punct& p);
	friend ostream& operator<<(ostream& os, Punct& p);
};

#endif