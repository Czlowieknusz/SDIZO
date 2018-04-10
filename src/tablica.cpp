#include <iostream>
#include "../include/tablica.h"

using namespace std;

// konstruktor inicjalizuj¹cy zmienne klasowe
Tablica::Tablica()
{
	Tablica::wskaznikNaHead = NULL;
	Tablica::rozmiarTablicy = 0;
}

// destruktor zwalniaj¹cy pamiêæ tablicy, jeœli ta istnieje
Tablica::~Tablica()
{
	if(wskaznikNaHead != NULL)
	{
		delete[] wskaznikNaHead;
	}
}

void Tablica::dodajNaPoczatek(int wartosc)
{
	// Alokuje pamiêæ na tablicê wiêksz¹ o jeden ni¿ poprzednio
	// Przypisz podan¹ wartoœæ na pierwszym miejscu

	int* nowyWskaznikNaHead = new int[rozmiarTablicy + 1];
	nowyWskaznikNaHead[0] = wartosc;

	// Zapisanie danych ze starj tablicy do nowej
	for(int i = 0; i < rozmiarTablicy; i++)
	{
		nowyWskaznikNaHead[i + 1] =  wskaznikNaHead[i];
	}

	// Zwolnienie pamiêci poprzedniej tablicy
	// Zast¹pienie jej wskaŸnikiem na g³owê nowej tablicy
	delete wskaznikNaHead;
	wskaznikNaHead = nowyWskaznikNaHead;

	// Inkrementacja zmiennej rozmiarTablicy
	rozmiarTablicy++;
}

void Tablica::dodajNaKoniec(int wartosc)
{
	// Alokuje pamiêæ na tablicê wiêksz¹ o jeden ni¿ poprzednio
	// Przypisz podan¹ wartoœæ na ostatnim miejscu

	int* nowyWskaznikNaHead = new int[rozmiarTablicy + 1];
	nowyWskaznikNaHead[rozmiarTablicy] = wartosc;

	// Zapisanie danych ze starj tablicy do nowej
	for(int i = 0; i < rozmiarTablicy; i++)
	{
		nowyWskaznikNaHead[i] = wskaznikNaHead[i];
	}

	// Zwolnienie pamiêci poprzedniej tablicy
	// Zast¹pienie jej wskaŸnikiem na g³owê nowej tablicy
	delete wskaznikNaHead;
	wskaznikNaHead = nowyWskaznikNaHead;

	// Inkrementacja zmiennej rozmiarTablicy
	rozmiarTablicy++;
}

void Tablica::dodajGdziekolwiek(int wartosc, int pozycja)
{
	if(pozycja < 0 || pozycja > rozmiarTablicy)
	{
		cout << "Tablica nie posiada pozycji o indeksie [" << pozycja << "]" << endl;
	}
	else
	{
		// Alokuje pamiêæ na tablicê wiêksz¹ o jeden ni¿ poprzednio
		// Przypisz podan¹ wartoœæ na ostatnim miejscu
		int* nowyWskaznikNaHead = new int[rozmiarTablicy + 1];
		nowyWskaznikNaHead[pozycja] = wartosc;

		// dopisz do nowej tablicy elementy przed podan¹ pozycj¹
		for(int i = 0; i < pozycja; i++)
		{
			nowyWskaznikNaHead[i] = wskaznikNaHead[i];
		}
		// dopisz pozosta³e elementy do pozycji
		for(int i = pozycja; i < rozmiarTablicy; i++)
		{
			nowyWskaznikNaHead[i + 1] = wskaznikNaHead[i];
		}

		// Zwolnienie pamiêci poprzednij tablicy
		delete wskaznikNaHead;
		// Zast¹pienie jej wskaŸnikiem na g³owê nowej tablicy
		wskaznikNaHead = nowyWskaznikNaHead;

		//Inkrementacja zmiennej rozmiarTablicy
		rozmiarTablicy++;
	}
}

void Tablica::usunOstatni()
{
	if(rozmiarTablicy > 0)
	{
		// Alokuje pamiêæ na tablicê mniejsz¹ o jeden ni¿ poprzednio
		int* nowyWskaznikNaHead = new int[rozmiarTablicy - 1];

		// Przypisuje elementy starej tablicy do nowej oprócz ostatniego
		for(int i = 0; i < rozmiarTablicy - 1; i++)
		{
			nowyWskaznikNaHead[i] = wskaznikNaHead[i];
		}

		// Zwolnienie pamiêci starej tablicy
		delete[] wskaznikNaHead;
		// Zast¹pienie jej wskaŸnikiem na g³owê nowej tablicy
		wskaznikNaHead = nowyWskaznikNaHead;

		// Inkrementacja zmiennej rozmiarTablicy
		rozmiarTablicy--;
	}
	else
	{
		cout << "Tablica jest pusta." << endl;
	}
}

void Tablica::usunPierwszy()
{
	// Sprawdzenie, czy tablica nie jest pusta
	if(rozmiarTablicy > 0)
	{
		// Alokuje pamiêæ na tablicê mniejsza o jeden element ni¿ poprzednio
		int* nowyWskaznikNaHead = new int(rozmiarTablicy - 1);

		// Przepisz element starej tablicy poza pierwszym
		for(int i = 0; i < rozmiarTablicy - 1; i++)
		{
			nowyWskaznikNaHead[i] = wskaznikNaHead[i + 1];
		}

		// Zwolnij pamiêæ starej tablicy
		delete[] wskaznikNaHead;
		// Przypisz wskaznik na nowa tablice to starego
		wskaznikNaHead = nowyWskaznikNaHead;

		//Dekrementuj rozmiar tablicy
		rozmiarTablicy--;
	}
}

void Tablica::usunJakikolwiek(int pozycja)
{
	// Sprawdzenie czy tablica nie jest pusta
	// Sprawdzenie czy podana pozycja nale¿y do tablicy
	if(rozmiarTablicy > 0 && pozycja > 0 && pozycja<rozmiarTablicy)
	{
		// Alokuje pamiêæ na tablicê mniejsz¹ o jeden element ni¿ poprzednio
		int* nowyWskaznikNaHead = new int[rozmiarTablicy - 1];

		// Przepisz elementy do podanej pozycji
		for(int i = 0; i < pozycja; i++)
		{
			nowyWskaznikNaHead[i] = wskaznikNaHead[i];
		}

		// Przepisz elementy po podanej pozycji
		for(int i = pozycja; i < rozmiarTablicy - 1; i++)
		{
			nowyWskaznikNaHead[i] = wskaznikNaHead[i + 1];
		}

		// Zwolnij pamiêæ po starym wskaŸniku
		delete[] wskaznikNaHead;
		// Przypisuje na jego miejsce nowy wskaŸnik
		wskaznikNaHead = nowyWskaznikNaHead;

		// Dekrementuje rozmiar tablicy o 1
		rozmiarTablicy--;
	}
	else
	{
		cout << "Tablica nie posiada tej pozycji [" << pozycja << "]" << endl;
	}
}

bool Tablica::sprawdzCzyIstnieje(int wartosc)
{
	// Przeszukaj tablicê pod k¹tem obecnoœci podanej wartoœci
	for (int i = 0; i < rozmiarTablicy; i++)
	{
		if(wskaznikNaHead[i] == wartosc)
		{
			cout << "Szukana wartoœæ znajduje siê w tablicy na pozycji [" << i << "]" << endl;
			return true;
		}
	}

	// Je¿eli wartoœæ nie wyst¹pi³a w tabeli zwróæ false
	cout << "Nie znaleziono podanej wartoœci w tablicy" << endl;
	return false;
}

void Tablica::wydrukujTablice()
{
	cout << "Elementy tablicy i ich wartoœci: " << endl;

	// SprawdŸ czy tablica nie jest pusta
	// Jeœli tak, wyœwietl stosowny komunikat
	// Je¿eli nie, wydrukuj j¹
	if(wskaznikNaHead != NULL)
	{
		for(int i = 0; i < rozmiarTablicy; i++)
			cout << "   [" << i << "] " << wskaznikNaHead[i] << endl;
	}
	else
	{
		cout << "	Tablica nie ma ¿adnych elementów" << endl;
	}
}
