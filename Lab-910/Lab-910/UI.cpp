#include "UI.h"

void UI::addProdus()
{
	Entitate p;
	std::cin >> p;
	this->service.addProdus(p.getCod(), p.getNume(), p.getPret());
}

void UI::findProdus()
{
	Entitate p;
	std::cin >> p;
	bool rez = this->service.findProdus(p.getCod(), p.getNume(), p.getPret());
	if (rez)
		std::cout << "Produsul a fost gasit" << std::endl;
	else
		std::cout << "Produsul nu a fost gasit" << std::endl;
}

void UI::updateProdus()
{
	Entitate pVechi, pNou;
	std::cout << "Introduceti produsul vechi" << std::endl;
	std::cin >> pVechi;
	std::cout << "Introduceti produsul nou" << std::endl;
	std::cin >> pNou;
	bool rez = this->service.updateProdus(pVechi.getCod(), pVechi.getNume(), pVechi.getPret(), 
		pNou.getCod(), pNou.getNume(), pNou.getPret());
	if (rez)
		std::cout << "Produsul a fost actualizat" << std::endl;
	else
		std::cout << "Produsul nu a fost gasit" << std::endl;
}

void UI::removeProdus()
{
	Entitate p;
	std::cin >> p;
	bool rez = this->service.removeProdus(p.getCod(), p.getNume(), p.getPret());
	if (rez)
		std::cout << "Produsul a fost sters" << std::endl;
	else
		std::cout << "Produsul nu a fost gasit" << std::endl;
}

void UI::printAll()
{
	std::cout << "Toate produsele sunt: " << std::endl;
	for (auto p : this->service.getAll())
		std::cout << p;
}

void UI::printSize()
{
	std::cout << "Numarul produselor este: " << this->service.getSize() << std::endl;
}

void UI::removeHigehrThanValue()
{
	int pret;
	std::cout << "Introduceti pretul produsului: ";
	std::cin >> pret;
	this->service.removeHigehrThanValue(pret);
}

void UI::buyAndGetChange()
{
	int cod;
	std::cout << "Introduceti codul produsului: " << std::endl;
	std::cin >> cod;
	int suma;
	std::cout << "Introduceti suma cu care vreti sa platiti: " << std::endl;
	std::cin >> suma;
	this->service.buyAndGetChange(cod, suma);
}

UI::UI()
{
}

UI::UI(Service& s)
{
	this->service = s;
}

UI::~UI()
{
}

void UI::runMeniu()
{
	char optiune;
	bool isRunning = 1;
	while (isRunning)
	{
		/*std::cout << "1. Adauga produs" << std::endl;
		std::cout << "2. Cauta produs" << std::endl;
		std::cout << "3. Actualizeaza produs" << std::endl;
		std::cout << "4. Sterge produs" << std::endl;
		std::cout << "5. Sterge toate produsele cu pretul mai mare decat o valoare " << std::endl;*/
		std::cout << "a. Afiseaza toate produsele" << std::endl;
		std::cout << "b. Cumpara produs" << std::endl;
		std::cout << "x. Inchide" << std::endl;
		std::cout << "Alegeti o optiune: ";
		std::cin >> optiune;
		
		switch (optiune)
		{
		/*case '1':
			addProdus();
			break;
		case '2':
			findProdus();
			break;
		case '3':
			updateProdus();
			break;
		case '4':
			removeProdus();
			break;
		case '5':
			removeHigehrThanValue();
			break;*/
		case 'a':
			printAll();
			break;
		case 'b':
			buyAndGetChange();
			break;
		case 'x':
			isRunning = 0;
			break;
		default:
			std::cout << "Optiune invalida!" << std::endl;
		}
	}
}
