#include "UI.h"

void UI::addTranzactie()
{
	std::cout << "Introduceti ziua tranzactiei: ";
	int zi;
	std::cin >> zi;
	std::cout << "Introduceti suma tranzactiei: ";
	int suma;
	std::cin >> suma;
	std::cin.ignore();
	char* tipStr = new char[100];
	bool tip, isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul tranzactiei (in/out): ";
		std::cin.getline(tipStr, 100);
		if (strcmp(tipStr, "in") == 0)
		{
			tip = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tipStr, "out") == 0)
			{
				tip = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	delete[] tipStr;
	std::cout << "Introduceti descrierea tranzactiei: ";
	char* descriere = new char[100];
	std::cin.getline(descriere, 100);
	this->service.addTranzactie(zi, suma, tip, descriere);
	delete[] descriere;
}

void UI::findTranzactie()
{
	std::cout << "Introduceti ziua tranzactiei: ";
	int zi;
	std::cin >> zi;
	std::cout << "Introduceti suma tranzactiei: ";
	int suma;
	std::cin >> suma;
	std::cin.ignore();
	char* tipStr = new char[100];
	bool tip, isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul tranzactiei (in/out): ";
		std::cin.getline(tipStr, 100);
		if (strcmp(tipStr, "in") == 0)
		{
			tip = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tipStr, "out") == 0)
			{
				tip = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	delete[] tipStr;
	std::cout << "Introduceti descrierea tranzactiei: ";
	char* descriere = new char[100];
	std::cin.getline(descriere, 100);
	bool rez = this->service.findTranzactie(zi, suma, tip, descriere);
	if (rez)
		std::cout << "Tranzactia a fost gasita" << std::endl;
	else
		std::cout << "Tranzactia nu a fost gasita" << std::endl;
	delete[] descriere;
}

void UI::updateTranzactie()
{
	std::cout << "Introduceti ziua veche: ";
	int ziVeche;
	std::cin >> ziVeche;
	std::cout << "Introduceti suma veche: ";
	int sumaVeche;
	std::cin >> sumaVeche;
	std::cin.ignore();
	char* tipStrVechi = new char[100];
	bool tipVechi, isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul vechi (in/out): ";
		std::cin.getline(tipStrVechi, 100);
		if (strcmp(tipStrVechi, "in") == 0)
		{
			tipVechi = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tipStrVechi, "out") == 0)
			{
				tipVechi = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	delete[] tipStrVechi;
	std::cout << "Introduceti descrierea veche: ";
	char* descriereVeche = new char[100];
	std::cin.getline(descriereVeche, 100);
	std::cout << "Introduceti ziua noua: ";
	int ziNoua;
	std::cin >> ziNoua;
	std::cout << "Introduceti suma noua: ";
	int sumaNoua;
	std::cin >> sumaNoua;
	std::cin.ignore();
	char* tipStrNou = new char[100];
	bool tipNou;
	isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul nou (in/out): ";
		std::cin.getline(tipStrNou, 100);
		if (strcmp(tipStrNou, "in") == 0)
		{
			tipNou = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tipStrNou, "out") == 0)
			{
				tipNou = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	delete[] tipStrNou;
	std::cout << "Introduceti descrierea noua: ";
	char* descriereNoua = new char[100];
	std::cin.getline(descriereNoua, 100);
	bool rez = this->service.updateTranzactie(ziVeche, sumaVeche, tipVechi, descriereVeche, 
		ziNoua, sumaNoua, tipNou, descriereNoua);
	if (rez)
		std::cout << "Tranzactia a fost modificata" << std::endl;
	else
		std::cout << "Tranzactia nu a fost gasita" << std::endl;
	delete[] descriereVeche, descriereNoua;
}

void UI::removeTranzactie()
{
	std::cout << "Introduceti ziua tranzactiei: ";
	int zi;
	std::cin >> zi;
	std::cout << "Introduceti suma tranzactiei: ";
	int suma;
	std::cin >> suma;
	std::cin.ignore();
	char* tipStr = new char[100];
	bool tip, isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul tranzactiei (in/out): ";
		std::cin.getline(tipStr, 100);
		if (strcmp(tipStr, "in") == 0)
		{
			tip = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tipStr, "out") == 0)
			{
				tip = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	delete[] tipStr;
	std::cout << "Introduceti descrierea tranzactiei: ";
	char* descriere = new char[100];
	std::cin.getline(descriere, 100);
	bool rez = this->service.removeTranzactie(zi, suma, tip, descriere);
	if (rez)
		std::cout << "Tranzactia a fost stearsa" << std::endl;
	else
		std::cout << "Tranzactia nu a fost gasita" << std::endl;
	delete[] descriere;
}

void UI::getAllTransactions()
{
	std::cout << "Toate tranzactiile sunt: " << std::endl;
	Entitate* all = this->service.getAllTransactions();
	for (int i = 0;i < this->service.numberOfTransactions();i++)
		std::cout << all[i];
}

void UI::numberOfTransactions()
{
	std::cout << "Numarul tranzactiilor este: " << this->service.numberOfTransactions() << std::endl;

}

void UI::removeAllInADay()
{
	int zi;
	std::cout << "Introduceti ziua tranzactiilor: ";
	std::cin >> zi;
	this->service.removeAllInADay(zi);
}

void UI::removeTranzactiiIntervalZile()
{
	int ziStart, ziStop;
	std::cout << "Introduceti ziua de inceput: ";
	std::cin >> ziStart;
	std::cout << "Introduceti ziua de sfarsit: ";
	std::cin >> ziStop;
	this->service.removeTranzactiiIntervalZile(ziStart, ziStop);
}

void UI::removeTranzactiiDupaTip()
{
	std::cin.ignore();
	char* tipStr = new char[100];
	bool tip, isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul tranzactiei (in/out): ";
		std::cin.getline(tipStr, 100);
		if (strcmp(tipStr, "in") == 0)
		{
			tip = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tipStr, "out") == 0)
			{
				tip = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	delete[] tipStr;
	this->service.removeTranzactiiDupaTip(tip);
}

void UI::printTranzactiiTip()
{
	std::cin.ignore();
	char* tipStr = new char[100];
	bool tip, isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul tranzactiei (in/out): ";
		std::cin.getline(tipStr, 100);
		if (strcmp(tipStr, "in") == 0)
		{
			tip = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tipStr, "out") == 0)
			{
				tip = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	delete[] tipStr;
	Entitate* all = this->service.getAllTransactions();
	for (int i = 0;i < this->service.numberOfTransactions();i++)
		if (all[i].getTip() == tip)
			std::cout << all[i];
}

void UI::printGreaterThanSum()
{
	std::cout << "Introduceti suma tranzactiei: ";
	int suma;
	std::cin >> suma;
	Entitate* all = this->service.getAllTransactions();
	for (int i = 0;i < this->service.numberOfTransactions();i++)
		if (all[i].getSuma() > suma)
			std::cout << all[i];
}

void UI::printEqualToSum()
{
	std::cout << "Introduceti suma tranzactiei: ";
	int suma;
	std::cin >> suma;
	Entitate* all = this->service.getAllTransactions();
	for (int i = 0;i < this->service.numberOfTransactions();i++)
		if (all[i].getSuma() == suma)
			std::cout << all[i];
}

void UI::printSoldZi()
{
	int zi;
	std::cout << "Introduceti ziua tranzactiilor: ";
	std::cin >> zi;
	std::cout << "Soldul pentru ziua " << zi << " este " << this->service.SoldZi(zi) << std::endl;
}

void UI::printSumaTip()
{
	std::cin.ignore();
	char* tipStr = new char[100];
	bool tip, isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul tranzactiei (in/out): ";
		std::cin.getline(tipStr, 100);
		if (strcmp(tipStr, "in") == 0)
		{
			tip = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tipStr, "out") == 0)
			{
				tip = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	std::cout << "Suma tranzactiilor de tip " << tipStr << " este " << this->service.sumaTip(tip) << std::endl;
	delete[] tipStr;
}

void UI::printMaxTipZi()
{
	std::cin.ignore();
	char* tipStr = new char[100];
	bool tip, isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul tranzactiei (in/out): ";
		std::cin.getline(tipStr, 100);
		if (strcmp(tipStr, "in") == 0)
		{
			tip = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tipStr, "out") == 0)
			{
				tip = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	delete[] tipStr;
	int zi;
	std::cout << "Introduceti ziua tranzactiilor: ";
	std::cin >> zi;
	Entitate max = this->service.maxTipZi(tip, zi);
	std::cout << max;
}

void UI::printFilterType()
{
	std::cin.ignore();
	char* tipStr = new char[100];
	bool tip, isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul tranzactiei (in/out): ";
		std::cin.getline(tipStr, 100);
		if (strcmp(tipStr, "in") == 0)
		{
			tip = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tipStr, "out") == 0)
			{
				tip = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	delete[] tipStr;
	std::vector<Entitate> rez = this->service.filterType(tip);
	if (rez.size() != 0)
		for (Entitate t : rez)
			std::cout << t;
}

void UI::printFilterTypeLessThanSum()
{
	std::cin.ignore();
	char* tipStr = new char[100];
	bool tip, isRunning = 1;
	while (isRunning)
	{
		std::cout << "Introduceti tipul tranzactiei (in/out): ";
		std::cin.getline(tipStr, 100);
		if (strcmp(tipStr, "in") == 0)
		{
			tip = 1;
			isRunning = 0;
		}
		else
			if (strcmp(tipStr, "out") == 0)
			{
				tip = 0;
				isRunning = 0;
			}
			else
				std::cout << "Tipul poate fi doar 'in' sau 'out'" << std::endl;
	}
	delete[] tipStr;
	std::cout << "Introduceti suma maxima: ";
	int sumaMax;
	std::cin >> sumaMax;
	std::vector<Entitate> rez = this->service.filterTypeLessThanSum(tip, sumaMax);
	if (rez.size() != 0)
		for (Entitate t : rez)
			std::cout << t;
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
	int optiune;
	bool isRunning = 1;
	while (isRunning)
	{
		std::cout << "1. Adauga tranzactie" << std::endl;
		std::cout << "2. Cauta tranzactie" << std::endl;
		std::cout << "3. Actualizeaza tranzactie" << std::endl;
		std::cout << "4. Sterge tranzactie" << std::endl;
		std::cout << "5. Sterge toate tranzactiile dintr-o zi" << std::endl;
		std::cout << "6. Sterge toate tranzactiile dintr-un interval de zile" << std::endl;
		std::cout << "7. Sterge toate tranzactiile de un anumit tip" << std::endl;
		std::cout << "8. Afiseaza toate tranzactiile" << std::endl;
		std::cout << "9. Afiseaza toate tranzactiile de un anumit tip" << std::endl;
		std::cout << "10. Afiseaza toate tranzactiile cu suma mai mare de o valoare" << std::endl;
		std::cout << "11. Afiseaza toate tranzactiile cu suma egala cu o valoare" << std::endl;
		std::cout << "12. Afiseaza soldul tranzactiilor dintr-o zi" << std::endl;
		std::cout << "13. Afiseaza suma tranzactiilor de un anumit tip" << std::endl;
		std::cout << "14. Afiseaza cea mai valoroasa tranzactie de un anumit tip dintr-o anumita zi" << std::endl;
		std::cout << "15. Filtreaza tranzactiile dupa tip" << std::endl;
		std::cout << "16. Filtreaza tranzactiile dupa tip si suma maxima" << std::endl;
		std::cout << "0. Inchide" << std::endl;
		std::cout << "Alegeti o optiune: ";
		std::cin >> optiune;
		switch (optiune)
		{
		case 0:
			isRunning = 0;
			break;
		case 1:
			addTranzactie();
			break;
		case 2:
			findTranzactie();
			break;
		case 3:
			updateTranzactie();
			break;
		case 4:
			removeTranzactie();
			break;
		case 5:
			removeAllInADay();
			break;
		case 6:
			removeTranzactiiIntervalZile();
			break;
		case 7:
			removeTranzactiiDupaTip();
			break;
		case 8:
			getAllTransactions();
			break;
		case 9:
			printTranzactiiTip();
			break;
		case 10:
			printGreaterThanSum();
			break;
		case 11:
			printEqualToSum();
			break;
		case 12:
			printSoldZi();
			break;
		case 13:
			printSumaTip();
			break;
		case 14:
			printMaxTipZi();
			break;
		case 15:
			printFilterType();
			break;
		case 16:
			printFilterTypeLessThanSum();
			break;
		default:
			std::cout << "Optiune invalida!" << std::endl;
		}
	}
}
