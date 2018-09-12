#include <iostream>

using namespace std;

class NNP{
private:
	int * arreglo;
	int tamanio;
public:

	//pregunta al usuario el tamaño del arreglo y se lo añade al apuntador
	NNP()
	{
		cout << "Dame el tamanio del arreglo que deseas" << endl;
		cin >> tamanio;
		arreglo = new int[tamanio]();
		//cout << "tamanio: " << tamanio << endl;
	};

	//añade el numero al arreglo
	void anadirNumero(const int posicion, const int numero )
	{
		if (posicion < 0)
			cout << "La posicion no debe ser negativa" << endl;
		else if (posicion > tamanio-1)
			cout << "La posicion no existe en el arreglo" << endl;
		else
		{
			bool nnp = comprobar(numero);
			if (nnp == true)
				arreglo[posicion] = numero;
			else
				cout << "El numero no es natural perfecto" << endl;
		}
		
		/*for (int i = 0; i < tamanio; i++)
			if (arreglo[i] != 0)
				cout << arreglo[i] << " ";
			else
				cout << "empty ";
		cout<<endl;*/
	}

	//comprueba que sea un NNP
	bool comprobar(const int numero)
	{
		int sum = 1;
		for (int i = 2; i <= numero/2; i++)
		{
			if (numero % i == 0)
				sum = sum + i;
		}

		if (sum == numero)
			return true;
		return false;
	}
};

int main()
{
	NNP arreglo;

	int posicion, numero; //numero a aniadir
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
			arreglo.anadirNumero(posicion, numero);
		}
		else if (opcion != 2)
			cout << "Opcion no disponible" << endl;
	}
	

	return 0;
}