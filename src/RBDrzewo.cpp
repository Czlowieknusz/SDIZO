#include "RBDrzewo.h"
#include "elementDrzewa.h"
#include <string>
#include <iostream>
#include <cstddef>

using namespace std;

RBDrzewo::RBDrzewo()
{
    licznik = 0;
    // ³añcuchy tekstu do drukowania drzewa
    cr = cl = cp = "  ";
    cr[0] = 218;
    cr[1] = 196;
    cl[0] = 192;
    cl[1] = 196;
    cp[0] = 179;
    // Inicjalizacja straznika
    s.kolor='B';
    s.ojciec=&s;
    s.lewySyn=&s;
    s.prawySyn=&s;
    korzen = &s;
}

RBDrzewo::~RBDrzewo()
{
    if(korzen)
        usunDrzewo(korzen);
}

// Rekurencyjne usuwanie drzewa
void RBDrzewo::usunDrzewo(ElementDrzewa* p)
{
    if(p!=&s)                       // sprawdzamy, czy element nie jest straznikiem
    {
        usunDrzewo(p->lewySyn);     // Usuwamy lewe poddrzewo
        usunDrzewo(p->prawySyn);    // Usuwamy prawe poddrzewo
        delete p;                   // Usuwamy sam węzeł

        RBDrzewo::licznik--;
    }
}

void RBDrzewo::rotL(ElementDrzewa* eD)
{
    ElementDrzewa* b,* p;

    b = eD->prawySyn;
    if(b != &s)
    {
        p = eD->ojciec;
        eD->prawySyn=b->lewySyn;
        if(eD->prawySyn!=&s)
            eD->prawySyn->ojciec = eD;
        b->lewySyn=eD;
        b->ojciec=p;
        eD->ojciec=b;

        if(p!=&s)
        {
            if(p->lewySyn==eD)
                p->lewySyn=b;
            else
                p->prawySyn=b;
        }
        else
            korzen = b;
    }
}

void RBDrzewo::rotR(ElementDrzewa* eD)
{
    ElementDrzewa *b, *p;

    b = eD->lewySyn;
    if(b!=&s)
    {
        p=eD->ojciec;
        eD->lewySyn=b->prawySyn;
        if(eD->lewySyn!=&s)
            eD->lewySyn->ojciec=eD;
        b->prawySyn=eD;
        b->ojciec=p;
        eD->ojciec=b;
        if(p!=&s)
        {
            if(p->lewySyn==eD)
                p->lewySyn=b;
            else
                p->prawySyn=b;
        }
        else
            korzen=b;
    }
}

void RBDrzewo::wstawElement(int wartosc)
{
    ElementDrzewa* x,* y;

    // nowy wêze³
    x = new ElementDrzewa;
    x->lewySyn=&s;
    x->prawySyn=&s;
    x->ojciec=korzen;
    x->wartosc=wartosc;

    // Przypisanie korzenia jako x, jezeli ojciec jest straznikiem
    // w przeciwnym wypadku, zastapienie liscia
    if(x->ojciec == &s)
        korzen = x;
    else
    {
        // Petla wyszukuj¹ca liœæ do zast¹pienia przez x
        while(true)
        {
            // x to prawy liœæ
            if(wartosc>x->ojciec->wartosc)
            {
                if(x->ojciec->prawySyn==&s)
                {
                    x->ojciec->prawySyn=x;
                    break;
                }
                x->ojciec=x->ojciec->prawySyn;
            }
            // x to lewy liœæ
            else
            {
                if(x->ojciec->lewySyn==&s)
                {
                    x->ojciec->lewySyn=x;
                    break;
                }
                x->ojciec = x->ojciec->lewySyn;
            }
        }
        // kolorowanie na czerwono
        x->kolor = 'R';
        while((x!=korzen)&& (x->ojciec->kolor == 'R'))
        {
            if(x->ojciec == x->ojciec->ojciec->lewySyn)
            {
                y = x->ojciec->ojciec->prawySyn;

                if(y->kolor=='R')
                {
                    x->ojciec->kolor='B';
                    y->kolor='B';
                    x->ojciec->ojciec->kolor='R';
                    x=x->ojciec->ojciec;
                    continue;
                }
                if(x==x->ojciec->prawySyn)
                {
                    x=x->ojciec;
                    rotL(x);
                }
                x->ojciec->kolor='B';
                x->ojciec->ojciec->kolor='R';
                rotR(x->ojciec->ojciec);
                break;
            }
            else
            {
                y=x->ojciec->ojciec->lewySyn;
                if(y->kolor=='R')
                {
                    x->ojciec->kolor='B';
                    y->kolor='B';
                    x->ojciec->ojciec->kolor='R';
                    x=x->ojciec->ojciec;
                    continue;
                }
                if(x==x->ojciec->lewySyn)
                {
                    x=x->ojciec;
                    rotR(x);
                }
                x->ojciec->kolor='B';
                x->ojciec->ojciec->kolor='R';
                rotL(x->ojciec->ojciec);
                break;
            }
        }
        korzen->kolor='B';
        licznik++;
    }
}

void RBDrzewo::usunWartosc(int wartosc)
{
    ElementDrzewa* elementUsuwany = 0;
    znajdzElement(wartosc, korzen, elementUsuwany);
    if(elementUsuwany == 0)
        return;
    wypiszWezel(elementUsuwany, "elemUsuw");

    ElementDrzewa* W,* Y,* Z;

    if((elementUsuwany->lewySyn == &s) || (elementUsuwany->prawySyn == &s))
        Y = elementUsuwany;
    else
        Y = znajdzNastepnyElement(elementUsuwany);
    wypiszWezel(Y,"Y");
    if(Y->lewySyn != &s)
        Z = Y->lewySyn;
    else
        Z = Y->prawySyn;

    Z->ojciec = Y->ojciec;
    wypiszWezel(Z,"Z");
    if(Y->ojciec == &s)
        korzen = Z;
    else if(Y == Y->ojciec->lewySyn)
        Y->ojciec->lewySyn=Z;
    else
        Y->ojciec->prawySyn=Z;
    wypiszWezel(Y->ojciec,"Ojciec Y");
    wypiszWezel(korzen,"Korzen");
    if(Y != elementUsuwany)
        elementUsuwany->wartosc = Y->wartosc;
    wypiszWezel(Y,"Y");
    if(Y->kolor == 'B')                 // Naprawa drzewa czerwono-czarnego
    {
        cout << "Wewnatrz ifa" << endl;
        while((Z != korzen) && (Z->kolor=='B'))
        {
            cout << "Petla."<<endl;
            if(Z== Z->ojciec->lewySyn)  // Przypadek 1
            {
                W = Z->ojciec->prawySyn;
                wypiszWezel(W,"W");
                if(W->kolor == 'R')
                {
                    W->kolor = 'B';
                    Z->ojciec->kolor='R';
                    rotL(Z->ojciec);
                    W = Z->ojciec->prawySyn;
                    cout << "Pierwszy if: "<<endl;
                    wypiszWezel(W,"W");
                    wypiszWezel(Z,"Z");
                }

                if((W->lewySyn->kolor == 'B') && (W->prawySyn->kolor == 'B'))   // Przypadek 2
                {
                    W->kolor = 'R';
                    Z = Z->ojciec;
                    cout << "Drugi if: "<<endl;
                    wypiszWezel(W,"W");
                    wypiszWezel(Z,"Z");
                    continue;
                }

                if(W->prawySyn->kolor == 'B')       // Przypadek 3
                {
                    W->lewySyn->kolor = 'B';
                    W->kolor= 'R';
                    rotR(W);
                    W = Z->ojciec->prawySyn;
                    cout << "Trzeci if: "<<endl;
                    wypiszWezel(W,"W");
                    wypiszWezel(Z,"Z");
                }

                W->kolor = Z->ojciec->kolor;        // Przypadek 4
                Z->ojciec->kolor = 'B';
                W->prawySyn->kolor = 'B';
                rotL(Z->ojciec);
                Z = korzen;
                cout<< "Czwarty przypadek: "<<endl;
                wypiszWezel(W,"W");
                wypiszWezel(Z,"Z");                         // To zakonczy petle
            }
            else                                    // Przypadki lustrzane
            {
                cout << "else: "<<endl;
                W = Z->ojciec->lewySyn;

                if(W->kolor=='R')                   // Przypadek 1
                {
                    W->kolor= 'B';
                    Z->ojciec->kolor = 'R';
                    rotR(Z->ojciec);
                    W = Z->ojciec->lewySyn;
                    cout << "Pierwszy if: "<<endl;
                    wypiszWezel(W,"W");
                    wypiszWezel(Z,"Z");
                }

                if((W->lewySyn->kolor == 'B') && (W->prawySyn->kolor == 'B'))       // Przypadek 2
                {
                    W->kolor = 'R';
                    Z = Z->ojciec;
                    cout << "Drugi if: "<<endl;
                    wypiszWezel(W,"W");
                    wypiszWezel(Z,"Z");
                    continue;
                }

                if(W->lewySyn->kolor == 'B')        // Przypadek 3
                {
                    W->prawySyn->kolor='B';
                    W->kolor='R';
                    rotL(W);
                    W = Z->ojciec->lewySyn;
                    cout << "Trzeci if: "<<endl;
                    wypiszWezel(W,"W");
                    wypiszWezel(Z,"Z");
                }

                W->kolor = Z->ojciec->kolor;;
                Z->ojciec->kolor = 'B';
                W->lewySyn->kolor = 'B';
                rotR(Z->ojciec);
                Z = korzen;
                cout << "Czwarty if: "<<endl;
                wypiszWezel(W,"W");
                wypiszWezel(Z,"Z");
            }

            Z->kolor = 'B';
            wypiszWezel(W,"W");
            wypiszWezel(Z,"Z");
            delete Y;
        }
    }
}

void RBDrzewo::znajdzElement(int wartosc, ElementDrzewa* korzenElementu, ElementDrzewa*& elementDoZnalezienia)
{
    if(korzenElementu!=&s)
    {
        if(korzenElementu->wartosc==wartosc)
        {
            elementDoZnalezienia = korzenElementu;
            return;
        }
        znajdzElement(wartosc, korzenElementu->lewySyn, elementDoZnalezienia);
        znajdzElement(wartosc, korzenElementu->prawySyn, elementDoZnalezienia);
    }
}

void RBDrzewo::sprawdzObecnosc(int wartosc)
{
    bool jestObecny = false;
    znajdzWartosc(wartosc, korzen, jestObecny);
    if(jestObecny)
    {
        cout << "Wartoœæ: " << wartosc << " zosta³a znaleziona w drzewie."<< endl;
    }
    else
    {
        cout << "Wartoœæ: " << wartosc << " nie zosta³a znaleziona w drzewie." << endl;
    }
}

void RBDrzewo::znajdzWartosc(int wartosc, ElementDrzewa* korzenElementu, bool& jestObecny)
{
    if(korzenElementu!=&s)
    {
        if(korzenElementu->wartosc==wartosc)
        {
            jestObecny=true;
            return;
        }
        znajdzWartosc(wartosc, korzenElementu->lewySyn, jestObecny);
        znajdzWartosc(wartosc, korzenElementu->prawySyn, jestObecny);
    }
}

ElementDrzewa* RBDrzewo::znajdzNastepnyElement(ElementDrzewa* w)
{
    ElementDrzewa* nastepny;

    if(w != &s)
    {
        if(w->prawySyn!=&s)
            return znajdzNajmniejszyElement(w->prawySyn);
        else
        {
            nastepny = w->ojciec;
            while((nastepny!=&s) && (w == nastepny->prawySyn))
            {
                w = nastepny;
                nastepny = nastepny->ojciec;
            }
            return nastepny;
        }
    }
    return &s;
}

ElementDrzewa* RBDrzewo::znajdzNajmniejszyElement(ElementDrzewa* w)
{
    if(w != &s)
        while(w->lewySyn!= &s)
            w=w->lewySyn;
    return w;
}

void RBDrzewo::drukujDrzewo()
{
    drukujDrzewo("","",korzen);
}

void RBDrzewo::drukujDrzewo(string sp, string sn, ElementDrzewa* p)
{
    string t;

    if(p != &s)
    {
        t = sp;
        if(sn== cr)
            t[t.length() - 2] = ' ';
        drukujDrzewo(t + cp, cr, p->prawySyn);

        t = t.substr(0, sp.length() - 2);

        cout << t << sn << p->kolor << ":" << p->wartosc << endl;

        t = sp;
        if(sn==cl)
            t[t.length()-2]=' ';
        drukujDrzewo(t + cp, cl, p->lewySyn);
    }
}

void RBDrzewo::wypiszWezel(ElementDrzewa* p, string s)
{
    cout << "Wartosc "<<s<<": " << p->wartosc << ", kolor: " << p->kolor << ", ojciec: "
         << p->ojciec->wartosc << ", prawy syn: " << p->prawySyn->wartosc << ", lewy syn: " << p->lewySyn->wartosc << endl;
}

