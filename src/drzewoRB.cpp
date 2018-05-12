#include "drzewoRB.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

drzewoRB::drzewoRB()
{
    cr = cl = cp = "  ";
    cr[0] = 218;
    cr[1] = 196;
    cl[0] = 192;
    cl[1] = 196;
    cp[0] = 179;
    S.kolor = 'B';
    S.ojciec = &S;
    S.lewySyn = &S;
    S.prawySyn = &S;
    korzen = &S;
}

drzewoRB::~drzewoRB()
{
    usunDrzewo(korzen);
}

void drzewoRB::usunDrzewo(ElementDrzewa* p)
{
    if(p != &S)
    {
        usunDrzewo(p->lewySyn);
        usunDrzewo(p->prawySyn);
        delete p;
    }
}

void drzewoRB::drukujRBT(string sp, string sn, ElementDrzewa* p)
{
    string t;

    if(p != &S)
    {
        t = sp;
        if(sn == cr)
            t[t.length() - 2] = ' ';
        drukujRBT(t + cp, cr, p->prawySyn);

        t = t.substr(0, sp.length() - 2);
        cout << t << sn << p->kolor << ":" << p->wartosc << endl;

        t = sp;
        if(sn == cl)
            t[t.length() - 2] = ' ';
        drukujRBT(t + cp, cl, p->lewySyn);
    }
}

void drzewoRB::drukujRBT()
{
    drukujRBT("", "", korzen);
}

ElementDrzewa* drzewoRB::znajdzWezel(int k)
{
    ElementDrzewa* p;

    p = korzen;
    while((p != &S) && (p->wartosc != k))
    {
        if(k < p->wartosc)
            p = p->lewySyn;
        else
            p = p->prawySyn;
    }
    if(p == &S)
        return NULL;
    return p;
}

ElementDrzewa* drzewoRB::znajdzMin(ElementDrzewa* p)
{
    if(p != &S)
        while(p->lewySyn != &S)
            p = p->lewySyn;
    return p;
}

ElementDrzewa* drzewoRB::znajdzNastepnik(ElementDrzewa* p)
{
    ElementDrzewa* r;

    if(p != &S)
    {
        if(p->prawySyn != &S)
            return znajdzMin(p->prawySyn);
        else
        {
            r = p->ojciec;
            while((r != &S) && (p == r->prawySyn))
            {
                p = r;
                r = r->ojciec;
            }
            return r;
        }
    }
    return &S;
}

void drzewoRB::rotL(ElementDrzewa* A)
{
    ElementDrzewa* B,* p;

    B = A->prawySyn;
    if(B != &S)
    {
        p = A->ojciec;
        A->prawySyn = B->lewySyn;

        if(A->prawySyn != &S)
            A->prawySyn->ojciec = A;

        B->lewySyn = A;
        B->ojciec = p;
        A->ojciec = B;

        if(p != &S)
        {
            if(p->lewySyn == A)
                p->lewySyn = B;
            else
                p->prawySyn = B;
        }
        else
            korzen = B;
    }
}

void drzewoRB::rotR(ElementDrzewa* A)
{
    ElementDrzewa* B, *p;

    B = A->lewySyn;
    if(B != &S)
    {
        p = A->ojciec;
        A->lewySyn = B->prawySyn;
        if(A->lewySyn != &S)
            A->lewySyn->ojciec = A;

        B->prawySyn = A;
        B->ojciec = p;
        A->ojciec = B;

        if(p != &S)
        {
            if(p->lewySyn == A)
                p->lewySyn = B;
            else
                p->prawySyn = B;
        }
        else
            korzen = B;
    }
}

void drzewoRB::wstawWezel(int k)
{
    ElementDrzewa* x,* y;

    x = new ElementDrzewa;
    x->lewySyn = &S;
    x->prawySyn = &S;
    x->ojciec = korzen;
    x->wartosc = k;
    if(x->ojciec == &S)
        korzen = x;
    else
        while(true)
        {
            if(k < x->ojciec->wartosc)
            {
                if(x->ojciec->lewySyn == &S)
                {
                    x->ojciec->lewySyn = x;
                    break;
                }
                x->ojciec = x->ojciec->lewySyn;
            }
            else
            {
                if(x->ojciec->prawySyn == &S)
                {
                    x->ojciec->prawySyn = x;
                    break;
                }
                x->ojciec = x->ojciec->prawySyn;
            }
        }
        x->kolor = 'R';
        while((x != korzen) && (x->ojciec->kolor == 'R'))
        {
            if(x->ojciec == x->ojciec->ojciec->lewySyn)
            {
                y = x->ojciec->ojciec->prawySyn;

                if(y->kolor == 'R')
                {
                    x->ojciec->kolor = 'B';
                    y->kolor = 'B';
                    x->ojciec->ojciec->kolor = 'R';
                    x = x->ojciec->ojciec;
                    continue;
                }

                if(x == x->ojciec->prawySyn)
                {
                    x = x->ojciec;
                    rotL(x);
                }

                x->ojciec->kolor = 'B';
                x->ojciec->ojciec->kolor = 'R';
                rotR(x->ojciec->ojciec);
                break;
            }
            else
            {
                y = x->ojciec->ojciec->lewySyn;

                if(y->kolor == 'R')
                {
                    x->ojciec->kolor = 'B';
                    y->kolor = 'B';
                    x->ojciec->ojciec->kolor = 'R';
                    x = x->ojciec->ojciec;
                    continue;
                }
                if(x == x->ojciec->lewySyn)
                {
                    x = x->ojciec;
                    rotR(x);
                }

                x->ojciec->kolor = 'B';
                x->ojciec->ojciec->kolor = 'R';
                rotL(x->ojciec->ojciec);
                break;
            }
        }
        korzen->kolor = 'B';
}

void drzewoRB::usunWezel(ElementDrzewa* x)
{
    ElementDrzewa* w,* y,* z;

    if((x->lewySyn == &S) || (x->prawySyn == &S))
        y = x;
    else
        y = znajdzNastepnik(x);

    if(y->lewySyn != &S)
        z = y->lewySyn;
    else
        z = y->prawySyn;

    z->ojciec = y->ojciec;

    if(y->ojciec == &S)
        korzen = z;
    else if(y == y->ojciec->lewySyn)
        y->ojciec->lewySyn = z;
    else
        y->ojciec->prawySyn = z;

    if(y != x)
        x->wartosc = y->wartosc;

    if(y->kolor == 'B')
    {
        while((z != korzen) && (z->kolor == 'B'))
        {
            if(z == z->ojciec->lewySyn)
            {
                w = z->ojciec->prawySyn;

                if(w->kolor == 'R')
                {
                    w->kolor = 'B';
                    z->ojciec->kolor = 'R';
                    rotL(z->ojciec);
                    w = z->ojciec->prawySyn;
                }

                if((w->lewySyn->kolor == 'B') && (w->prawySyn->kolor == 'B'))
                {
                    w->kolor = 'R';
                    z = z->ojciec;
                    continue;
                }

                if(w->prawySyn->kolor == 'B')
                {
                    w->lewySyn->kolor = 'B';
                    w->kolor = 'R';
                    rotR(w);
                    w = z->ojciec->prawySyn;
                }

                w->kolor = z->ojciec->kolor;
                z->ojciec->kolor = 'B';
                w->prawySyn->kolor = 'B';
                rotL(z->ojciec);
                z = korzen;
            }
            else
            {
                w = z->ojciec->lewySyn;

                if(w->kolor == 'R')
                {
                    w->kolor = 'B';
                    z->ojciec->kolor = 'R';
                    rotR(z->ojciec);
                    w = z->ojciec->lewySyn;
                }

                if((w->lewySyn->kolor == 'B') && (w->prawySyn->kolor == 'B'))
                {
                    w->kolor = 'R';
                    z = z->ojciec;
                    continue;
                }

                if(w->lewySyn->kolor == 'B')
                {
                    w->prawySyn->kolor = 'B';
                    w->kolor = 'R';
                    rotL(w);
                    w = z->ojciec->lewySyn;
                }

                w->kolor = z->ojciec->kolor;
                z->ojciec->kolor = 'B';
                w->lewySyn->kolor = 'B';
                rotR(z->ojciec);
                z = korzen;
            }
        }
    }
    z->kolor = 'B';

    delete y;
}

void drzewoRB::sprawdzObecnosc(int wartosc)
{
    ElementDrzewa* el = new ElementDrzewa;
    el = znajdzWezel(wartosc);
    if(el == NULL)
    {
        cout << "Wartoœæ: " << wartosc << " zosta³a znaleziona w drzewie."<< endl;
    }
    else
    {
        cout << "Wartoœæ: " << wartosc << " nie zosta³a znaleziona w drzewie." << endl;
    }
}
