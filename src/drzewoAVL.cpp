#include "drzewoAVL.h"
#include "ElementAVL.h"
#include <iostream>
#include <iomanip>

#define NULL 0

using namespace std;

drzewoAVL::drzewoAVL()
{
    korzen=NULL;
    licznik = 0;
}

drzewoAVL::~drzewoAVL()
{
    while(korzen)
        delete(usunElement(korzen));
}

// Rotacja RR
ElementAVL* drzewoAVL::rotacjaRR(ElementAVL* A)
{
    ElementAVL* B = A->prawySyn,* P = A->ojciec;

    A->prawySyn = B->lewySyn;
    if(A->prawySyn)
        A->prawySyn->ojciec = A;
    B->lewySyn = A;
    B->ojciec = P;
    A->ojciec = B;
    if(P)
    {
        if(P->lewySyn == A)
            P->lewySyn = B;
        else
            P->prawySyn = B;
    }
    else
        korzen = B;

    if(B->wywazenie == -1)
        A->wywazenie = B->wywazenie = 0;
    else
    {
        A->wywazenie = -1;
        B->wywazenie = 1;
    }
    return B;
}

// Rotacja LL
ElementAVL* drzewoAVL::rotacjaLL(ElementAVL* A)
{
    ElementAVL* B = A->lewySyn,* P = A->ojciec;

    A->lewySyn = B->prawySyn;
    if(A->lewySyn)
        A->lewySyn->ojciec = A;
    B->prawySyn = A;
    B->ojciec = P;
    A->ojciec = B;
    if(P)
    {
        if(P->lewySyn == A)
            P->lewySyn = B;
        else
            P->prawySyn = B;
    }
    else
        korzen = B;

    if(B->wywazenie == 1)
        A->wywazenie = B->wywazenie = 0;
    else
    {
        A->wywazenie = 1;
        B->wywazenie = -1;
    }
    return B;
}

// Rotacja RL
ElementAVL* drzewoAVL::rotacjaRL(ElementAVL* A)
{
    ElementAVL* B = A->prawySyn,* C = B->lewySyn,* P = A->ojciec;
    B->lewySyn = C->prawySyn;
    if(B->lewySyn)
        B->lewySyn->ojciec = B;
    A->prawySyn = C->lewySyn;
    if(A->prawySyn)
        A->prawySyn->ojciec = A;
    C->lewySyn = A;
    C->prawySyn = B;
    A->ojciec = B->ojciec = C;
    C->ojciec = P;
    if(P)
    {
        if(P->lewySyn == A)
            P->lewySyn = C;
        else
            P->prawySyn = C;
    }
    else
        korzen = C;

    A->wywazenie = (C->wywazenie == -1) ? 1 : 0;
    B->wywazenie = (C->wywazenie == 1) ? -11 : 0;
    C->wywazenie = 0;

    return C;
}

// Rotacja LR
ElementAVL* drzewoAVL::rotacjaLR(ElementAVL* A)
{
    ElementAVL* B = A->lewySyn,* C = B->prawySyn,* P = A->ojciec;

    B->prawySyn = C->lewySyn;
    if(B->prawySyn)
        B->prawySyn->ojciec = B;
    A->lewySyn = C->prawySyn;
    if(A->lewySyn)
        A->lewySyn->ojciec = A;
    C->prawySyn = A;
    C->lewySyn = B;
    A->ojciec = B->ojciec = C;
    C->ojciec = P;
    if(P)
    {
        if(P->lewySyn == A)
            P->lewySyn = C;
        else
            P->prawySyn = C;
    }
    else
        korzen = C;
    A->wywazenie = (C->wywazenie == 1) ? -1 : 0;
    B->wywazenie = (C->wywazenie == -1) ? 1 : 0;
    C->wywazenie = 0;

    return C;
}

// Wstawianie elementu do struktury AVL
void drzewoAVL::wstawElement(ElementAVL* A)
{
    ElementAVL* x = korzen,* y,* z;

    y = A->lewySyn = A->prawySyn = NULL;
    A->wywazenie = 0;

    while(x)
    {
        y = x;
        x = (A->wartosc < x->wartosc) ? x->lewySyn : x->prawySyn;
    }

    licznik++;

    if(!(A->ojciec = y))
    {
        korzen = A;
        return;
    }
    if(A->wartosc < y->wartosc)
        y->lewySyn = A;
    else
        y->prawySyn = A;
    if(y->wywazenie)
    {
        y->wywazenie = 0;
        return;
    }
    y->wywazenie = (y->lewySyn == A) ? 1 : -1;
    z= y->ojciec;
    while(z)
    {
        if(z->wywazenie)
            break;
        z->wywazenie = (z->lewySyn == y) ? 1 : -1;
        y = z;
        z = z->ojciec;
    }

    if(!z)
        return;

    if(z->wywazenie == 1)
    {
        if(z->prawySyn == y)
        {
            z->wywazenie = 0;
            return;
        }
        if(y->wywazenie == -1)
            rotacjaLR(z);
        else
            rotacjaLL(z);
        return;
    }
    else
    {
        if(z->lewySyn == y)
        {
            z->wywazenie = 0;
            return;
        }
        if(y->wywazenie == 1)
            rotacjaRL(z);
        else
            rotacjaRR(z);
        return;
    }
}

// Wyszukuje element o podanej wartosci
ElementAVL* drzewoAVL::znajdzElement(int wartosc)
{
    ElementAVL* x = korzen;

    while((x) && (x->wartosc != wartosc))
        x = (wartosc < x->wartosc) ? x->lewySyn : x->prawySyn;

    return x;
}

// Zwraca najmniejsza watosc klucza
int drzewoAVL::znajdzNajmniejszy(ElementAVL* A)
{
    while(A->lewySyn)
        A = A->lewySyn;
    return A->wartosc;
}

// Zwraca najwieksza watosc klucza
int drzewoAVL::znajdzNajwiekszy(ElementAVL* A)
{
    while(A->prawySyn)
        A = A->prawySyn;
    return A->wartosc;
}

// Zwraca element o najwekszej wartosci
ElementAVL* drzewoAVL::znajdzNajwiekszyElement(ElementAVL* A)
{
    while(A->prawySyn)
        A = A->prawySyn;
    return A;
}

// Zwraca element o najmniejszej wartosci
ElementAVL* drzewoAVL::znajdzNajmniejszyElement(ElementAVL* A)
{
    while(A->lewySyn)
        A = A->lewySyn;
    return A;
}

// Zwraca element poprzednika
ElementAVL* drzewoAVL::znajdzPoprzednik(ElementAVL* A)
{
    if(A->lewySyn)
        return znajdzNajwiekszyElement(A->lewySyn);
    ElementAVL* y;

    do
    {
        y=A;
        A=A->ojciec;
    }
    while(A&& (A->prawySyn != y));
    return A;
}

// Zwraca element nastepnika
ElementAVL* drzewoAVL::znajdzNastepnik(ElementAVL* A)
{
    if(A->prawySyn)
        return znajdzNajmniejszyElement(A->prawySyn);
    return NULL;
}

// Usuwa element A ze struktury AVL. Zwraca usunięty element
ElementAVL* drzewoAVL::usunElement(ElementAVL* A)
{
    ElementAVL* t,* y,* z;
    bool nest;

    if((A->lewySyn) && (A->prawySyn))
    {
        y = usunElement(znajdzPoprzednik(A));
        licznik++;
        nest = false;
    }
    else
    {
        if(A->lewySyn)
        {
            y = A->lewySyn;
            A->lewySyn = NULL;
        }
        else
        {
            y = A->prawySyn;
            A->prawySyn = NULL;
        }
        A->wywazenie = 0;
        nest = true;
    }

    if(y)
    {
        y->ojciec = A->ojciec;
        if((y->lewySyn = A->lewySyn))
            y->lewySyn->ojciec = y;
        if((y->prawySyn = A->prawySyn))
            y->prawySyn->ojciec = y;
        y->wywazenie = A->wywazenie;
    }

    if(A->ojciec)
    {
        if(A->ojciec->lewySyn == A)
            A->ojciec->lewySyn = y;
        else
            A->ojciec->prawySyn = y;
    }
    else
        korzen = y;

    if(nest)
    {
        z = y;
        y = A->ojciec;
        while(y)
        {
            // Przypadek 1
            if(!(y->wywazenie))
            {
                y->wywazenie = (y->lewySyn == z) ? -1 : 1;
                break;
            }
            else
            {
                // Przypadek 2
                if(((y->wywazenie == 1) && (y->lewySyn == z)) || ((y->wywazenie == -1) && (y->prawySyn == z)))
                {
                    y->wywazenie = 0;
                    z = y;
                    y = y->ojciec;
                }
                else
                {
                    t = (y->lewySyn == z) ? y->prawySyn : y->lewySyn;

                    // Przypadek 3.1
                    if(!(t->wywazenie))
                    {
                        if(y->wywazenie == 1)
                            rotacjaLL(y);
                        else
                            rotacjaRR(y);
                        break;
                    }
                    // Przypadk 3.2
                    else if(y->wywazenie == t->wywazenie)
                    {
                        if(y->wywazenie == 1)
                            rotacjaLL(y);
                        else
                            rotacjaRR(y);
                        z = t;
                        y=t->ojciec;
                    }
                    // Przypadek 3.3
                    else
                    {
                        if(y->wywazenie == 1)
                            rotacjaLR(y);
                        else
                            rotacjaRL(y);
                        z = y->ojciec;
                        y = z->ojciec;
                    }
                }
            }
        }
    }
    licznik--;
    return A;
}

// Drukuje drzewo metoda preorder
void drzewoAVL::preorder(ElementAVL* A)
{
    if(A)
    {
        cout << A->wartosc << endl;
        preorder(A->lewySyn);
        preorder(A->prawySyn);
    }
}

// Drukuje drzewo metoda inorder
void drzewoAVL::inorder(ElementAVL* A)
{
    if(A)
    {
        inorder(A->lewySyn);
        cout << A->wartosc << endl;
        inorder(A->prawySyn);
    }
}

// Drukuje drzewo metoda postorder
void drzewoAVL::postorder(ElementAVL* A)
{
    if(A)
    {
        postorder(A->lewySyn);
        postorder(A->prawySyn);
        cout << A->wartosc << endl;
    }
}

// Przechodzi przez drzewo wypisujac zawartosc elementow
void drzewoAVL::wydrukujDrzewo(ElementAVL* A)
{
    cout << A->wartosc << " : wspolczynnik wywazenia = " << setw(2) << A->wywazenie << " : lewy syn-> ";
    if(A->lewySyn)
        cout << setw(3) << A->lewySyn->wartosc;
    else
        cout << "NIL";
    cout << ", prawy syn-> ";
    if(A->prawySyn)
        cout << setw(3) << A->prawySyn->wartosc;
    else
        cout << "NIL";
    cout << " : ojciec -> ";
    if(A->ojciec)
        cout << setw(3) << A->ojciec->wartosc;
    else
        cout << "NIL";
    cout << endl;
    if(A->lewySyn)
        wydrukujDrzewo(A->lewySyn);
    if(A->prawySyn)
        wydrukujDrzewo(A->prawySyn);
}

// Wywoluje funkcje rekurencyjna drukujaca drzewo
void drzewoAVL::wydrukujDrzewo()
{
    wydrukujDrzewo(korzen);
}

// Wypisuje liczbe elementow w drzewie
void drzewoAVL::wypiszIloscElementow()
{
    cout << endl << "Liczba elementow w drzewie AVL: " << licznik << endl;
}

void drzewoAVL::usunElement(int wartosc)
{
    usunElement(znajdzElement(wartosc));
}

void drzewoAVL::wstawElement(int wartosc)
{
    ElementAVL* element = new ElementAVL;
    element->wartosc = wartosc;
    wstawElement(element);
}

void drzewoAVL::drukujDrzewo()
{
    drukujDrzewo("","",korzen);
}

void drzewoAVL::drukujDrzewo(string sp, string sn, ElementAVL* p)
{
    // ³añcuchy tekstu do drukowania drzewa
    string cr, cl, cp;
    cr = cl = cp = "  ";
    cr[0] = 218;
    cr[1] = 196;
    cl[0] = 192;
    cl[1] = 196;
    cp[0] = 179;
    string t;

    if(p != NULL)
    {
        t = sp;
        if(sn== cr)
            t[t.length() - 2] = ' ';
        drukujDrzewo(t + cp, cr, p->prawySyn);

        t = t.substr(0, sp.length() - 2);

        cout << t << sn << p->wartosc << endl;

        t = sp;
        if(sn==cl)
            t[t.length()-2]=' ';
        drukujDrzewo(t + cp, cl, p->lewySyn);
    }
}

void drzewoAVL::wydrukujElement(int wartosc)
{
    ElementAVL* element = new ElementAVL;
    element = znajdzElement(wartosc);
    if(element)
        cout << "Element zostal znaleziony."<<endl;
    else
        cout << "Element nie zostal znaleziony w drzewie." << endl;
}
