#include <iostream>
#include "../include/kopiec.h"
#include <cstddef>

using namespace std;

// Konstruktor
Kopiec::Kopiec()
{
	Kopiec::tablica = NULL;
	Kopiec::rozmiar = 0;
}

// Destruktor
Kopiec::~Kopiec()
{
	if(Kopiec::rozmiar > 0)
		delete[] tablica;
}

void Kopiec::dodaj(int wartosc)
{
	// Sprawdzenie czy podana wartoœc nie wyst¹pi³a ju¿ wczeœniej w kopcu
	if(!Kopiec::sprawdzCzyIstnieje(wartosc))
	{
		//Stwórz now¹ tablicê wiêksz¹ o jeden element
		int* nowaTablica = new int[rozmiar + 1];

		// Przepisz wszystkie wartoœci ze starej tablicy do nowej
		for(int i = 0; i < rozmiar; i++)
		{
			nowaTablica[i] = tablica[i];
		}

		// dodaj na koñcu nowy element
		nowaTablica[rozmiar] = wartosc;

		// Usuñ star¹ tablicê
		delete[] tablica;

		// Przypisz wskaŸnik na now¹ tablicê do wskaŸnika tablica
		tablica = nowaTablica;

		// Uporz¹dkuj strukturê kopca
		Kopiec::poprawStrukture();

		// Inkrementuj rozmiar
		rozmiar++;
	}
}

void Kopiec::usun(int wartosc)
{
	// Przeszukanie tablicy pod k¹tem obecnoœci danej wartoœci
	for(int i = 0; i < rozmiar; i++)
	{
		if(tablica[i] == wartosc)
		{
			// Stworzenie nowej tablicy o mniejszej pojemnoœci
			int* nowaTablica = new int[rozmiar - 1];

			// Przepisz elementy do pozycji o indeksie i
			for(int j = 0; j < i; j++)
			{
				nowaTablica[j] = tablica[j];
			}

			// Przepisz resztê tablicy
			for(int j = i + 1; j < rozmiar; j++)
			{
				nowaTablica[j - 1] = tablica[j];
			}

			// Usuñ star¹ tablicê
			delete[] tablica;

			// Przypisz now¹ tablicê w miejsce starej
			tablica = nowaTablica;

			// Zmniejsz rozmiar tablicy
			rozmiar--;

			// Popraw kolejnoœæ elementów w tablicy kopca
			Kopiec::poprawStrukture();
			return;
		}
	}
}

void Kopiec::poprawStrukturePoDodaniu()
{
	// Pomocnicza zmienna do sortowania
	int bufor;
	int obecnaPozycja = rozmiar - 1;
	while(obecnaPozycja != 0)
	{
		if(tablica[(obecnaPozycja - 1) / 2] < tablica[obecnaPozycja])
		{
			bufor = tablica[obecnaPozycja];
			tablica[obecnaPozycja] = tablica[(obecnaPozycja - 1) / 2];
			tablica[(obecnaPozycja - 1) / 2] = bufor;
		}
	}
}

void Kopiec::poprawStrukture()
{
	// Pomocnicza zmienna do sortowania
	int bufor;

	// Pêtla sortuj¹ca
	for(int i = rozmiar; 0 < i; i--)
	{
		if(tablica[i - 1] < tablica[i])
		{
			bufor = tablica[i - 1];
			tablica[i - 1] = tablica[i];
			tablica[i] = bufor;
		}
	}
}

bool Kopiec::sprawdzCzyIstnieje(int wartosc)
{
    for(int i =0; i<rozmiar; i++)
    {
        // Przerwij, jeśli wartość zostanie odnaleziona
        if(tablica[i]==wartosc)
        {
            cout<< "Wartość odnaleziona na pozycji ["<<i<<"]"<<endl;
            return true;
        }
    }
    return false;
}

void Kopiec::wydrukujKopiec()
{
    // Sprawdź, czy kopiec nie jest pusty
    // Jeśli tak poinformuj użytkownika
    // Jeśli nie wydrukuj kopiec
    if(tablica!=NULL)
    {
        cout << "Kopiec posiada elementy: " << endl;
        for(int i = 0; i<rozmiar;i++)
        {
            cout << "   ["<<i<<"] "<< tablica[i];
        }
    }
    else
    {
        cout << "Kopiec jest pusty";
    }
}
