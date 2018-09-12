#include<iostream>

using namespace std;

class ArrayNatPerfect;

//comprueba que sea un NNP
bool comprobar(const int numero)
{
	int sum = 1;
	for (int i = 2; i <= numero / 2; i++)
	{
		if (numero % i == 0)
			sum = sum + i;
	}

	if (sum == numero)
		return true;
	return false;
}

class Proxy
{
	ArrayNatPerfect& arr;
	int idx;
public:
	Proxy(ArrayNatPerfect& arr, int idx) : arr(arr), idx(idx){}
	Proxy& operator = (int value);
	friend ostream& operator<<(ostream&, Proxy&&);
};

class ArrayNatPerfect
{
private:
	int * arr;
	int size;

public:
	friend class Proxy;
	ArrayNatPerfect(int size) : size(size)
	{
		arr = new int[size + 1]; //EL MAS 1 ES PARA REDIRIGIR ERRORES
	}
	Proxy operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			cout << "Error: No hay índices negativos" << endl;
			return Proxy(*this, size);
		}
		return Proxy(*this, index);
	}
	friend ostream& operator<<(ostream& os, Proxy&& p);
};

Proxy& Proxy::operator = (int value)
{
	bool nnp = comprobar(value);

	if (nnp == true)
	//if (value >= 0) //natural perfecto
	{
		arr.arr[idx] = value;
	}
	else
	{
		cout << "Eror no es natural perfecto" << endl;
	}
	return *this;
}

ostream& operator<<(ostream& os, Proxy&& p)
{
	os << p.arr.arr[p.idx];
	return os;
}

int main()
{
	int tamanio, posicion, numero;
	cout << "de que tamanio sera el arreglo?" << endl;
	cin >> tamanio;
	ArrayNatPerfect a(tamanio);

	int opcion = 1;
	while (opcion != 2)
	{
		cout << "Que desea hacer?" << endl
			<< "1) Aniadir un numero" << endl
			<< "2) Salir" << endl;
		cin >> opcion;

		if (opcion == 1)
		{
			cout << "Cual numero aniadiras?" << endl;
			cin >> numero;
			cout << "En que posicion?" << endl;
			cin >> posicion;

			a[posicion] = numero;
		}
		else if (opcion != 2)
			cout << "Opcion no disponible" << endl;
	}

	return 0;
}
