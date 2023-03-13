#include "UI.h"

void UI::removeIncapere()
{
	Incapere i;
	std::cin >> i;
	bool rez = this->service.removeIncapere(i.getTimp(), i.getMod());
	if (rez)
		std::cout << "Incaperea a fost stearsa" << std::endl;
	else
		std::cout << "Incaperea nu a fost gasita" << std::endl;
}

void UI::printAll()
{
	std::cout << "Toate incaperile sunt: " << std::endl;
	for (auto i : this->service.getAll())
		std::cout << i;
}

UI::UI() {}

UI::UI(Service& s)
{
	this->service = s;
}

UI::~UI() {}

void UI::runMeniu()
{
	char optiune;
	bool isRunning = 1;
	while (isRunning)
	{
		std::cout << "1. Sterge incapere" << std::endl;
		std::cout << "a. Afiseaza toate incaperile" << std::endl;
		std::cout << "x. Inchide" << std::endl;
		std::cout << "Alegeti o optiune: ";
		std::cin >> optiune;

		switch (optiune)
		{
			case '1':
				removeIncapere();
				break;
		case 'a':
			printAll();
			break;
		case 'x':
			isRunning = 0;
			break;
		default:
			std::cout << "Optiune invalida!" << std::endl;
		}
	}
}
