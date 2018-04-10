#include "../include/licznikCzasu.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

// Funkcja zapisuje do zmiennej czasPoczatek bie¿¹cy czas
void LicznikCzasu::czasStart()
{
	czasPoczatek = high_resolution_clock::now();
}

// Funkcja zapisuje do zmiennej czasKoniec bie¿¹cy czas
void LicznikCzasu::czasStop()
{
	czasKoniec = high_resolution_clock::now();
}

// Funkcja zwraca ró¿nicê miêdzy czasKoniec i czasPocz¹tek
long LicznikCzasu::czasOperacji()
{
	return duration_cast<nanoseconds>(LicznikCzasu::czasKoniec - LicznikCzasu::czasPoczatek).count();
}
