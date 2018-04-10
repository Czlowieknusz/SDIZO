#include <iostream>
#include "../include/dzialania.h"
#include "../include/kopiec.h"
#include "../include/tablica.h"
#include "../include/lista.h"

using namespace std;

int main(int argc, char** argv)
{
	//Inicjalizacja klasy testującej
    Dzialania dzialania;
    int wybor = -1;
    //string tn = "n";

    cout << "SDIZO: PROJEKT 1\nAutor: Jan Woźniak\nNr indeksu: 234995\n" << endl << endl;


    //Początkowe menu wyboru
    while (wybor != 0) {
        cout << "Wybierz test:" << endl;
        cout << "    1. Tablica Dynamiczna" << endl;
        cout << "    2. Lista" << endl;
        cout << "    3. Kopiec Binarny" << endl;
        cout << "    4. Drzewo Czerowno-Czarne" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return 0;

        //cout << "Automatyzować test? (t/n): ";
        //cin >> tn;

        switch (wybor) {
            default:
                cout << "Błędny wybór!" << endl;
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
