#include <iostream>
#include <stddef.h>
#include "../include/lista.h"

using namespace std;

Lista::Lista()
{
	Lista::pierwszyElement = NULL;
	Lista::ostatniElement = NULL;
	Lista::aktualnyElement = NULL;
	Lista::rozmiar = 0;
}

Lista::~Lista()
{
	for(int i = 0; i<Lista::rozmiar; i++)
	{
		// Przypisuje kolejny element do aktualnyElement
		aktualnyElement = pierwszyElement->nastepny;

		// Usuñ pierwszy element
		delete pierwszyElement;

		// Przypisz aktualnyElement do pierwszyElement
		pierwszyElement = aktualnyElement;
	}
}

void Lista::dodajNaPoczatek(int wartosc)
{
	// Sprawdzenie, czy lista nie jest pusta
	if(pierwszyElement == NULL)
	{
		// Uwórz element, nastêpnie ustaw go jako element pocz¹tkowy i koñcowy
		pierwszyElement = new ElementListy(wartosc, NULL, NULL);
		ostatniElement = pierwszyElement;
	}
	else
	{
		// Ustaw element pierwszy jako aktualny
		aktualnyElement = pierwszyElement;

		// utworzenie nowego elementu i przypisanie go jako pierwszyElement
		pierwszyElement = new ElementListy(wartosc, aktualnyElement, NULL);
		aktualnyElement->poprzedni = pierwszyElement;
	}

	// Inkrementacja rozmiaru listy
	rozmiar++;
}

void Lista::dodajNaKoniec(int wartosc)
{
	//Sprawdzenie czy lista nie jest pusta
	if(pierwszyElement == NULL)
	{
		// Uwórz element, nastêpnie ustaw go jako element pocz¹tkowy i koñcowy
		pierwszyElement = new ElementListy(wartosc, NULL, NULL);
		ostatniElement = pierwszyElement;
	}
	else
	{
		// Ustaw ostatni element jako aktualny
		aktualnyElement = ostatniElement;

		// utworzenie nowego elementu i przypisanie go jako ostatniElement
		ostatniElement = new ElementListy(wartosc, aktualnyElement, NULL);
		aktualnyElement->nastepny = ostatniElement;
	}

	// Inkrementacja rozmiaru
	rozmiar++;
}

void Lista::dodajGdziekolwiek(int wartosc, int pozycja)
{
    cout << "Ostatni element: " << ostatniElement->wartosc<<endl;
	// Sprawdz czy lista posiada dan¹ pozycjê
	if(pozycja < 0 || pozycja > rozmiar)
	{
		cout << "Lista nie posiada pozycji [" << pozycja << "]" << endl;
		return;
	}

	// Sprawdz czy dana pozycja jest pierwsz¹
	if(pozycja == 0)
	{
		Lista::dodajNaPoczatek(wartosc);
		return;
	}

	// Sprawdz czy dana pozycja jest ostatni¹
	if(pozycja == rozmiar)
	{
		Lista::dodajNaKoniec(wartosc);
		return;
	}

	// Sprawdzenie w której po³owie listy znajduje siê wybrany element
	// w celu przyspieszenia obliczeñ
	if(pozycja < rozmiar / 2)
	{
		// Przypisz pierwszy element za aktualny
		aktualnyElement = pierwszyElement;

		// Przesuñ aktualnyElement do danej pozycji
		for(int i = 1; i < pozycja; ++i)
		{
			aktualnyElement = aktualnyElement->nastepny;
		}
	}
	else
	{
		//Przypisz element ostatni za aktualny
		aktualnyElement = ostatniElement;

		// Przesuñ wszystkie elementy o jedn¹ pozycjê wstecz
		for(int i = 0; i < rozmiar - pozycja; ++i)
		{
			aktualnyElement = aktualnyElement->poprzedni;
		}
	}
	// Stwórz nowy element listy z podanymi parametrami
	ElementListy* nowyElementListy = new ElementListy(wartosc, aktualnyElement->nastepny, aktualnyElement);

	// Przypisz nowy element na danej pozycji listy
	aktualnyElement->nastepny->poprzedni = nowyElementListy;
	aktualnyElement->nastepny = nowyElementListy;

	// Inkrementacja rozmiaru
	rozmiar++;
}

void Lista::usunPierwszy()
{
    if(pierwszyElement==NULL)
    {
        cout << "Lista jest pusta."<<endl;
        return;
    }
	// Przypisz drugi element jako aktualny
	aktualnyElement = pierwszyElement->nastepny;

	// Usuñ pierwszy element
	delete pierwszyElement;

	// Sprawdzenie czy w liœcie s¹ inne elementy
	// Je¿eli tak, przypisz aktualny element jako pierwsze
	// Je¿eli nie, nullujemy elementy listy
	if(rozmiar > 1)
	{
		aktualnyElement->poprzedni = NULL;
		pierwszyElement = aktualnyElement;
	}
	else
	{
		aktualnyElement = NULL;
		pierwszyElement = NULL;
		ostatniElement = NULL;
	}

	// Dekrementuj rozmiar
	rozmiar--;
}

void Lista::usunOstatni()
{
    if(pierwszyElement==NULL)
    {
        cout << "Lista jest pusta."<<endl;
        return;
    }
	// Przypisz przedostatni element jako aktualny
	aktualnyElement = ostatniElement->poprzedni;

	// Usuñ ostatni element
	delete ostatniElement;

	// Sprawdzenie czy w liœcie s¹ inne elementy
	// Je¿eli tak, przypisz aktualny element jako pierwsze
	// Je¿eli nie, nullujemy elementy listy
	if(rozmiar > 1)
	{
		aktualnyElement->nastepny = NULL;
		ostatniElement = aktualnyElement;
	}
	else
	{
		aktualnyElement = NULL;
		pierwszyElement = NULL;
		ostatniElement = NULL;
	}

	// Dekrementuj rozmiar
	rozmiar--;
}

void Lista::usunKtorykolwiek(int pozycja)
{
	//Sprawdzenie czy na liœcie istnieje dana pozycja
	if(pozycja < 0 || pozycja >= rozmiar)
	{
		cout << "Lista nie posiada danej pozycji [" << pozycja << "]" << endl;
		return;
	}

	//Sprawdzenie czy dana pozycja jest pierwsza
	if(pozycja == 0)
	{
		usunPierwszy();
		return;
	}

	// Sprawdzenie czy dana pozycja jest ostatnia
	if(pozycja == rozmiar - 1)
	{
		usunOstatni();
		return;
	}

	// Sprawdzenie w której po³owie listy znajduje siê wybrany element
	if(pozycja < rozmiar / 2)
	{
		//Przypisz za aktualny element pierwszy
		aktualnyElement = pierwszyElement;

		//Przesuñ aktualnyElement do danej pozycji
		for(int i = 1; i < pozycja; ++i)
		{
			aktualnyElement = aktualnyElement->nastepny;
		}
	}
	else
	{
		// Przypisz za aktualny element ostatni
		aktualnyElement = ostatniElement;

		// Przesuñ aktualnyElement do danej pozycji
		for (int i = 0; i < rozmiar - pozycja; ++i)
		{
			aktualnyElement = aktualnyElement->poprzedni;
		}
	}

	// Stwórz nowy wskaźnik na element do usunięcia
	ElementListy* nowyElementListy = aktualnyElement->nastepny;

	aktualnyElement->nastepny=nowyElementListy->nastepny;
	aktualnyElement->nastepny->poprzedni=aktualnyElement;

	delete nowyElementListy;

	// Dekrementuj rozmiar
	rozmiar--;
}

bool Lista::sprawdzCzyIstnieje(int wartosc)
{
	// Je¿eli lista jest pusta, zwróæ false z automatu
	if(rozmiar == 0)
	{
		return false;
	}

	// Przypisz pierwszy element do aktualnego
	aktualnyElement = pierwszyElement;

	// Przeszukaj listê pod k¹tem wartoœci
	for(int i = 0; i < rozmiar; i++)
	{
		if(aktualnyElement->wartosc == wartosc)
		{
			cout << "Wartoœæ znaleziona na pozycji [" << i << "]" << endl;
			return true;
		}

		aktualnyElement = aktualnyElement->nastepny;
	}

	// Zwróæ false je¿eli wartoœæ nie znalaz³a siê na liœcie
	cout << "Nie znaleziono wartoœci w liœcie" << endl;
	return false;
}


void Lista::wydrukujListe()
{
	// Przypisz do aktualnyElement pierwszyElement
	aktualnyElement = pierwszyElement;

	for(int i = 0; i < rozmiar; i++)
	{
		cout << "[" << i << "] " << aktualnyElement->wartosc << endl;

		// Przypisz kolejny element listy jako aktualn
		aktualnyElement = aktualnyElement->nastepny;
	}
}
