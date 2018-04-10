#pragma once
class Tablica
{
public:
	// Zmienne
	int* wskaznikNaHead;
	int rozmiarTablicy;

	Tablica();

	//Detruktor
	~Tablica();

	// Metody
	void dodajNaPoczatek(int);
	void dodajNaKoniec(int);
	void dodajGdziekolwiek(int wartosc, int pozycja);
	void usunOstatni();
	void usunPierwszy();
	void usunJakikolwiek(int);
	void wydrukujTablice();
	bool sprawdzCzyIstnieje(int wartosc);
};
