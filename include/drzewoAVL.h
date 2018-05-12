#ifndef DRZEWOAVL_H
#define DRZEWOAVL_H

#include "ElementAVL.h"
#include <string>

using namespace std;

class drzewoAVL
{
    public:
        ElementAVL* korzen;
        int licznik;

        drzewoAVL();
        ~drzewoAVL();
        ElementAVL* rotacjaRR(ElementAVL*);
        ElementAVL* rotacjaLL(ElementAVL*);
        ElementAVL* rotacjaRL(ElementAVL*);
        ElementAVL* rotacjaLR(ElementAVL*);
        void wstawElement(ElementAVL*);
        void wstawElement(int);
        ElementAVL* znajdzElement(int);
        int znajdzNajwiekszy(ElementAVL*);
        int znajdzNajmniejszy(ElementAVL*);
        ElementAVL* znajdzNajwiekszyElement(ElementAVL*);
        ElementAVL* znajdzNajmniejszyElement(ElementAVL*);
        ElementAVL* znajdzNastepnik(ElementAVL*);
        ElementAVL* znajdzPoprzednik(ElementAVL*);
        ElementAVL* usunElement(ElementAVL*);
        void usunElement(int);
        void preorder(ElementAVL*);
        void inorder(ElementAVL*);
        void postorder(ElementAVL*);
        void wydrukujDrzewo();
        void wydrukujDrzewo(ElementAVL*);
        void wydrukujElement(int);
        void wypiszIloscElementow();
        void drukujDrzewo();
        void drukujDrzewo(string,string,ElementAVL*);
};

#endif // DRZEWOAVL_H
