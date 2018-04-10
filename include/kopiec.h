#include "tablica.h"
class Kopiec
{
    public:
	int* tablica;
	int rozmiar;

	Kopiec();
	~Kopiec();

	void dodaj(int);
	void usun(int);
	void poprawStrukture();
	void poprawStrukturePoDodaniu();
	void wydrukujKopiec();
	bool sprawdzCzyIstnieje(int);
	int iloscPoziomow();
};
