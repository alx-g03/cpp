#ifndef VALUTA_H
#define VALUTA_H

class Valuta {
private:
	int valoare;
public:
	Valuta();
	Valuta(int valoare);
	Valuta(const Valuta& v);
	~Valuta();
	void setValoare(int valoare);
	int getValoare();
	Valuta& operator=(const Valuta& v);
	bool operator== (const Valuta& v);
};

#endif