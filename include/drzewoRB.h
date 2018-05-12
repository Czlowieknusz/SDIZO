#ifndef DRZEWORB_H
#define DRZEWORB_H

#include "elementDrzewa.h"
#include <string>

using namespace std;

class drzewoRB
{
        ElementDrzewa* korzen;
        ElementDrzewa S;
        string cr, cl, cp;
        void drukujRBT(string, string, ElementDrzewa*);

        public:
        drzewoRB();
        ~drzewoRB();
        void usunDrzewo(ElementDrzewa*);
        void drukujRBT();
        ElementDrzewa* znajdzWezel(int);
        ElementDrzewa* znajdzMin(ElementDrzewa*);
        ElementDrzewa* znajdzNastepnik(ElementDrzewa*);
        void rotL(ElementDrzewa*);
        void rotR(ElementDrzewa*);
        void wstawWezel(int);
        void usunWezel(ElementDrzewa*);
        void sprawdzObecnosc(int);
};

#endif // DRZEWORB_H
