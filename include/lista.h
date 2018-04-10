#include "elementListy.h"

class Lista
{
public:
	   	int rozmiar;
	   	
	   	Lista();
	   	
	   	~Lista();
	   	
	   	ElementListy* pierwszyElement;
	   	ElementListy* ostatniElement;
	   	ElementListy* aktualnyElement;
	   	
	   	void dodajNaPoczatek(int wartosc);
	   	
	   	void dodajGdziekolwiek(int wartosc, int pozycja);
	   	
	   	void dodajNaKoniec(int watosc);
	   	
	   	void wydrukujListe();
	   	
	   	void usunPierwszy();
	   	
	   	void usunOstatni();
	   	
	   	void usunKtorykolwiek(int);
	   	
	   	bool sprawdzCzyIstnieje(int wartosc);
};