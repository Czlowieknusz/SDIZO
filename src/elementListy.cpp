#include <iostream>
#include "../include/elementListy.h"

ElementListy::ElementListy(int wartosc, ElementListy* nastepny, ElementListy* poprzedni)
{
	ElementListy::wartosc = wartosc;
	ElementListy::nastepny = nastepny;
	ElementListy::poprzedni = poprzedni;
}
