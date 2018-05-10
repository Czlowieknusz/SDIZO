#include <iostream>
#include "../include/licznikCzasu.h"
#include "../include/tablica.h"
#include "../include/kopiec.h"
#include "../include/lista.h"
#include "../include/RBDrzewo.h"
#include "../include/dzialania.h"

using namespace std;

void Dzialania::dzialaniaTablica()
{
    LicznikCzasu licznikCzasu;
    Tablica tablica;
    int opcja = -1;
    int wartosc;
    int pozycja;

    while (opcja != 0)
    {
        cout << "Wybierz operację: " << endl;
        cout << "    1. Dodaj na początek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuń pierwszy" << endl;
        cout << "    5. Usuń ostatni" << endl;
        cout << "    6. Usuń którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj tablicę" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> opcja;
        switch (opcja)
        {
        default:
            cout << "Nie ma takiej operacji!" << endl;
            break;

        case 0:
            break;

        case 1:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            tablica.dodajNaPoczatek(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 2:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            tablica.dodajNaKoniec(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 3:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            cout << "Podaj pozycję: ";
            cin >> pozycja;
            licznikCzasu.czasStart();
            tablica.dodajGdziekolwiek(wartosc, pozycja);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 4:
            licznikCzasu.czasStart();
            tablica.usunPierwszy();
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 5:
            licznikCzasu.czasStart();
            tablica.usunOstatni();
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 6:
            cout << "Podaj pozycję: ";
            cin >> pozycja;
            licznikCzasu.czasStart();
            tablica.usunJakikolwiek(pozycja);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 7:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            tablica.sprawdzCzyIstnieje(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 8:
            licznikCzasu.czasStart();
            tablica.wydrukujTablice();
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;
        }

    }
}

void Dzialania::dzialaniaLista()
{
    LicznikCzasu licznikCzasu;
    Lista lista;
    int opcja = -1;
    int wartosc;
    int pozycja;

    while (opcja != 0)
    {
        cout << "Wybierz funkcję listy:" << endl;
        cout << "    1. Dodaj na początek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuń pierwszy" << endl;
        cout << "    5. Usuń ostatni" << endl;
        cout << "    6. Usuń którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj listę" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> opcja;
        switch (opcja)
        {
        default:
            cout << "Błędny wybór!" << endl;
            break;

        case 0:
            break;

        case 1:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            lista.dodajNaPoczatek(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 2:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            lista.dodajNaKoniec(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 3:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            cout << "Podaj pozycję: ";
            cin >> pozycja;
            licznikCzasu.czasStart();
            lista.dodajGdziekolwiek(wartosc, pozycja);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 4:
            licznikCzasu.czasStart();
            lista.usunPierwszy();
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 5:
            licznikCzasu.czasStart();
            lista.usunOstatni();
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 6:
            cout << "Podaj pozycję: ";
            cin >> pozycja;
            licznikCzasu.czasStart();
            lista.usunKtorykolwiek(pozycja);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 7:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            lista.sprawdzCzyIstnieje(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 8:
            licznikCzasu.czasStart();
            lista.wydrukujListe();
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        }

    }
}

void Dzialania::dzialaniaKopiec()
{
    LicznikCzasu licznikCzasu;
    Kopiec kopiec;
    int wybor = 99;
    int wartosc;
    while (wybor != 0)
    {
        cout << "Wybierz funkcję Kopca:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuń" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj kopiec" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;
        switch (wybor)
        {
        default:
            cout << "Błędny wybór!" << endl;
            break;

        case 0:
            break;

        case 1:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            kopiec.dodaj(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 2:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            kopiec.usun(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 3:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            kopiec.sprawdzCzyIstnieje(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 4:
            licznikCzasu.czasStart();
            kopiec.wydrukujKopiec();
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;
        }

    }
}

void Dzialania::dzialaniaRBT()
{
    LicznikCzasu licznikCzasu;
    RBDrzewo drzewo;
    int wybor = 99;
    int wartosc;
    while (wybor != 0)
    {
        cout << "Wybierz funkcję drzewa:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuń" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj drzewo" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;
        switch (wybor)
        {
        default:
            cout << "Błędny wybór!" << endl;
            break;

        case 0:
            break;

        case 1:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            drzewo.wstawElement(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 2:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            drzewo.usunWartosc(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 3:
            cout << "Podaj wartość: ";
            cin >> wartosc;
            licznikCzasu.czasStart();
            drzewo.sprawdzObecnosc(wartosc);
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;

        case 4:
            licznikCzasu.czasStart();
            drzewo.drukujDrzewo();
            licznikCzasu.czasStop();
            cout << "Czas operacji: " << licznikCzasu.czasOperacji() << "ms" << endl;
            break;
        }

    }
}
