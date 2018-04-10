class ElementListy
{
	public:
		ElementListy* nastepny;
		ElementListy* poprzedni;
		int wartosc;
		
		ElementListy(int, ElementListy*, ElementListy*);
};