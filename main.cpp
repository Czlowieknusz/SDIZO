#include <iostream>
#include "include/kopiec.h"
#include "include/lista.h"
#include "include/tablica.h"
#include "include/dzialania.h"

using namespace std;

int main(int argc, char** argv)
{
	//Inicjalizacja klasy testuj¹cej
    Dzialania dzialania;
    int wybor = -1;
    //string tn = "n";

    cout << "SDIZO: PROJEKT 1\nAutor: Jan WoŸniak\nNr indeksu: 234995\n" << endl << endl;


    //Pocz¹tkowe menu wyboru
    while (wybor != 0) {
        cout << "Wybierz test:" << endl;
        cout << "    1. Tablica Dynamiczna" << endl;
        cout << "    2. Lista" << endl;
        cout << "    3. Kopiec Binarny" << endl;
        cout << "    4. Drzewo Czerowno-Czarne" << endl;
        cout << "    0. Wyjœcie" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;

        //Zamknij, je¿eli wybrano 0
        if (wybor == 0) return 0;

        //cout << "Automatyzowaæ test? (t/n): ";
        //cin >> tn;

        switch (wybor) {
            default:
                cout << "B³êdny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Rozpoczynam test tablicy dynamicznej..." << endl;
                //if (tn == "t") testyAutomatyczne.testTablicy();
                //else testy.testTablicy();
                dzialania.dzialaniaTablica();
                break;

            case 2:
                cout << "Rozpoczynam test listy..." << endl;
                //if (tn == "t") testyAutomatyczne.testListy();
                //else testy.testListy();
                dzialania.dzialaniaLista();
                break;

            case 3:
                cout << "Rozpoczynam test kopca binarnego..." << endl;
                //if (tn == "t") testyAutomatyczne.testKopca();
                //else testy.testKopca();
                dzialania.dzialaniaKopiec();
                break;
        }
    }
    return 0;
}
