#include <chrono>

using namespace std;
using namespace std::chrono;

class LicznikCzasu
{
public:
	high_resolution_clock::time_point czasPoczatek;
	high_resolution_clock::time_point czasKoniec;

	void czasStart();

	void czasStop();

	long czasOperacji();
};
