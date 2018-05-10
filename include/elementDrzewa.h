#ifndef ELEMENTDRZEWA_H
#define ELEMENTDRZEWA_H


class ElementDrzewa
{
    public:
        ElementDrzewa* ojciec;
        ElementDrzewa* prawySyn;
        ElementDrzewa* lewySyn;
        char kolor;
        int wartosc;
};

#endif // ELEMENTDRZEWA_H
