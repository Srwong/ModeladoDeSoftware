//Manuel Hernandez A01022089

#include <iostream>
#include <time.h>

using namespace std;

class Relog
{
public:
	time_t hora;
	char* obtenerHora(time_t& hora);
};


int main()
{
	Relog r;
	cout << r.obtenerHora(r.hora) << endl;
	return 0;
}

char* Relog::obtenerHora(time_t& hora)
{
	hora = time(0);
	char* time = ctime(&hora);
	return time;
}