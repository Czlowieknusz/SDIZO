#ifndef RBDRZEWO_H
#define RBDRZEWO_H

#include "elementDrzewa.h"
#include <string>

using namespace std;

class RBDrzewo
{
    public:
        ElementDrzewa s;        // Straznik
        ElementDrzewa* korzen;  // korzen drzewa czerwono-czarnego
        string cr,cl,cp;          // ³añcuchy do znaków ramek?

        int licznik;

        void drukujDrzewo();
        void drukujDrzewo(string, string, ElementDrzewa*);  // Wypisuje drzewo
        void znajdzWartosc(int, ElementDrzewa*, bool&);
        void znajdzElement(int, ElementDrzewa*, ElementDrzewa*&);
        ElementDrzewa* znajdzNastepnyElement(ElementDrzewa*);
        ElementDrzewa* znajdzNajmniejszyElement(ElementDrzewa*);
        void sprawdzObecnosc(int);
        void rotL(ElementDrzewa*);
        void rotR(ElementDrzewa*);
        void wstawElement(int);
        void usunElement(ElementDrzewa*);
        void usunWartosc(int);
        void usunDrzewo(ElementDrzewa*);
        void wypiszWezel(ElementDrzewa*,string);

        RBDrzewo();
        ~RBDrzewo();
};

#endif // RBDRZEWO_H
