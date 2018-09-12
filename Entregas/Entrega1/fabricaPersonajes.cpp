//Manuel Hernández A01022089
#include <iostream>
#include <string>

using namespace std;

class ReinoSingleton
{
private:
	string nombreReino;
	static ReinoSingleton* instance;

	ReinoSingleton()
	{
		instance = this;
	}

public:

	static ReinoSingleton* getInstance()
	{
		if (instance == 0)
			ReinoSingleton();
		return instance;
	}

	void getReino()
	{
		cout << instance << endl;
	}

	void setReino(string nuevoNombre)
	{
		nombreReino = nuevoNombre;
	}
};

class Personaje
{
public:
	virtual void correr() = 0;
};

class Principe : public Personaje
{
public:
	void seleccionarArma();
	void atacar();
	void correr()
	{
		cout << "El principe corre rápido" << endl;
	}
};

class Princesa : public Personaje
{
public:
	void gritar();
	void correr()
	{
		cout << "La princesa corre medio lento" << endl;
	}
};

class Villano : public Personaje
{
public:
	void atacar();
	void atraparPricnesa();
	void correr()
	{
		cout << "El villano no necesita correr" << endl;
	}
};

class VillanoVolador : public Personaje
{
public:
	void correr()
	{
		cout << "También puede volar" << endl;
	}
};

ReinoSingleton *ReinoSingleton::instance = 0;

int main()
{
	Villano v;
	Princesa p;
	Principe pri;
	VillanoVolador vv;

	v.correr();
	p.correr();
	pri.correr();
	vv.correr();

	ReinoSingleton *reino = ReinoSingleton::getInstance();

	reino->getReino();

	return 1;
}
