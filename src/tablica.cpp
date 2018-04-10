#include <iostream>
#include "../include/tablica.h"

using namespace std;

// konstruktor inicjalizuj�cy zmienne klasowe
Tablica::Tablica()
{
	Tablica::wskaznikNaHead = NULL;
	Tablica::rozmiarTablicy = 0;
}

// destruktor zwalniaj�cy pami�� tablicy, je�li ta istnieje
Tablica::~Tablica()
{
	if(wskaznikNaHead != NULL)
	{
		delete[] wskaznikNaHead;
	}
}

void Tablica::dodajNaPoczatek(int wartosc)
{
	// Alokuje pami�� na tablic� wi�ksz� o jeden ni� poprzednio
	// Przypisz podan� warto�� na pierwszym miejscu

	int* nowyWskaznikNaHead = new int[rozmiarTablicy + 1];
	nowyWskaznikNaHead[0] = wartosc;

	// Zapisanie danych ze starj tablicy do nowej
	for(int i = 0; i < rozmiarTablicy; i++)
	{
		nowyWskaznikNaHead[i + 1] =  wskaznikNaHead[i];
	}

	// Zwolnienie pami�ci poprzedniej tablicy
	// Zast�pienie jej wska�nikiem na g�ow� nowej tablicy
	delete wskaznikNaHead;
	wskaznikNaHead = nowyWskaznikNaHead;

	// Inkrementacja zmiennej rozmiarTablicy
	rozmiarTablicy++;
}

void Tablica::dodajNaKoniec(int wartosc)
{
	// Alokuje pami�� na tablic� wi�ksz� o jeden ni� poprzednio
	// Przypisz podan� warto�� na ostatnim miejscu

	int* nowyWskaznikNaHead = new int[rozmiarTablicy + 1];
	nowyWskaznikNaHead[rozmiarTablicy] = wartosc;

	// Zapisanie danych ze starj tablicy do nowej
	for(int i = 0; i < rozmiarTablicy; i++)
	{
		nowyWskaznikNaHead[i] = wskaznikNaHead[i];
	}

	// Zwolnienie pami�ci poprzedniej tablicy
	// Zast�pienie jej wska�nikiem na g�ow� nowej tablicy
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
		// Alokuje pami�� na tablic� wi�ksz� o jeden ni� poprzednio
		// Przypisz podan� warto�� na ostatnim miejscu
		int* nowyWskaznikNaHead = new int[rozmiarTablicy + 1];
		nowyWskaznikNaHead[pozycja] = wartosc;

		// dopisz do nowej tablicy elementy przed podan� pozycj�
		for(int i = 0; i < pozycja; i++)
		{
			nowyWskaznikNaHead[i] = wskaznikNaHead[i];
		}
		// dopisz pozosta�e elementy do pozycji
		for(int i = pozycja; i < rozmiarTablicy; i++)
		{
			nowyWskaznikNaHead[i + 1] = wskaznikNaHead[i];
		}

		// Zwolnienie pami�ci poprzednij tablicy
		delete wskaznikNaHead;
		// Zast�pienie jej wska�nikiem na g�ow� nowej tablicy
		wskaznikNaHead = nowyWskaznikNaHead;

		//Inkrementacja zmiennej rozmiarTablicy
		rozmiarTablicy++;
	}
}

void Tablica::usunOstatni()
{
	if(rozmiarTablicy > 0)
	{
		// Alokuje pami�� na tablic� mniejsz� o jeden ni� poprzednio
		int* nowyWskaznikNaHead = new int[rozmiarTablicy - 1];

		// Przypisuje elementy starej tablicy do nowej opr�cz ostatniego
		for(int i = 0; i < rozmiarTablicy - 1; i++)
		{
			nowyWskaznikNaHead[i] = wskaznikNaHead[i];
		}

		// Zwolnienie pami�ci starej tablicy
		delete[] wskaznikNaHead;
		// Zast�pienie jej wska�nikiem na g�ow� nowej tablicy
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
		// Alokuje pami�� na tablic� mniejsza o jeden element ni� poprzednio
		int* nowyWskaznikNaHead = new int(rozmiarTablicy - 1);

		// Przepisz element starej tablicy poza pierwszym
		for(int i = 0; i < rozmiarTablicy - 1; i++)
		{
			nowyWskaznikNaHead[i] = wskaznikNaHead[i + 1];
		}

		// Zwolnij pami�� starej tablicy
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
	// Sprawdzenie czy podana pozycja nale�y do tablicy
	if(rozmiarTablicy > 0 && pozycja > 0 && pozycja<rozmiarTablicy)
	{
		// Alokuje pami�� na tablic� mniejsz� o jeden element ni� poprzednio
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

		// Zwolnij pami�� po starym wska�niku
		delete[] wskaznikNaHead;
		// Przypisuje na jego miejsce nowy wska�nik
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
	// Przeszukaj tablic� pod k�tem obecno�ci podanej warto�ci
	for (int i = 0; i < rozmiarTablicy; i++)
	{
		if(wskaznikNaHead[i] == wartosc)
		{
			cout << "Szukana warto�� znajduje si� w tablicy na pozycji [" << i << "]" << endl;
			return true;
		}
	}

	// Je�eli warto�� nie wyst�pi�a w tabeli zwr�� false
	cout << "Nie znaleziono podanej warto�ci w tablicy" << endl;
	return false;
}

void Tablica::wydrukujTablice()
{
	cout << "Elementy tablicy i ich warto�ci: " << endl;

	// Sprawd� czy tablica nie jest pusta
	// Je�li tak, wy�wietl stosowny komunikat
	// Je�eli nie, wydrukuj j�
	if(wskaznikNaHead != NULL)
	{
		for(int i = 0; i < rozmiarTablicy; i++)
			cout << "   [" << i << "] " << wskaznikNaHead[i] << endl;
	}
	else
	{
		cout << "	Tablica nie ma �adnych element�w" << endl;
	}
}
