//Manuel Hernandez A01022089
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Videojuego{
private:
	string nombre;
	double precio;
	long int numeroSerie;
	string subgenero;

public:
	void setNombre(string temp) { nombre = temp; }
	void setPrecio(double temp) { precio = temp; }
	void setNumSerie(long int temp) { numeroSerie = temp; }
	void setSubGenero(string temp) { subgenero = temp; }
	virtual void setAtributoExtra(string ext) = 0;

	string getNombre() { return nombre; }
	double getPrecio() { return precio; }
	long int getNumSerie() { return numeroSerie; }
	string getSubGenero() { return subgenero; }
	virtual string getAtributoExtra() = 0;
	

	virtual void concepcion() = 0;

	virtual void diseno() = 0;

	virtual void planificacion() = 0;

	virtual void produccion() = 0;

	virtual void pruebasAceptacion() = 0;

	virtual Videojuego* clonar() = 0;
};

template <class T>
class ClonVideojuego : public Videojuego{
public:
	virtual Videojuego* clonar()
	{
		return new T(dynamic_cast<T&>(*this));
	}
};

//Lucha y Arcade
class Estrategia : public ClonVideojuego < Estrategia > {
private:
	string desarrollador;
public:

	void setAtributoExtra(string ext){ desarrollador = ext; }
	string getAtributoExtra() { return desarrollador; }

	void concepcion()
	{
		cout << "Estrategia: concepcion" << endl;
	}

	void diseno()
	{
		cout << "Estrategia: disenio" << endl;
	}

	void planificacion()
	{
		cout << "Estrategia: planificacion" << endl;
	}

	void produccion()
	{
		cout << "Estrategia: produccion" << endl;
	}

	void pruebasAceptacion()
	{
		cout << "Estrategia: pruebas de aceptacion" << endl;
	}

	void setDesarrollador(string d)
	{
		desarrollador = d;
	}
};

//Plataforma y Gráfica
class Aventura : public ClonVideojuego < Aventura > {
private:
	string paisOrigen;
public:
	void setAtributoExtra(string ext){ paisOrigen = ext; }
	string getAtributoExtra() { return paisOrigen; }

	void concepcion()
	{
		cout << "Aventura: concepcion" << endl;
	}

	void diseno()
	{
		cout << "Aventura: disenio" << endl;
	}

	void planificacion()
	{
		cout << "Aventura: planificacion" << endl;
	}

	void produccion()
	{
		cout << "Aventura: produccion" << endl;
	}

	void pruebasAceptacion()
	{
		cout << "Aventura: pruebas de aceptacion" << endl;
	}
};

//Idioma y musica;
class Aprendizaje : public ClonVideojuego < Aventura > {
private:
	string idioma;
public:
	void setAtributoExtra(string ext){ idioma = ext; }
	string getAtributoExtra() { return idioma; }

	void concepcion()
	{
		cout << "Aprensizaje: concepcion" << endl;
	}

	void diseno()
	{
		cout << "Aprensizaje: disenio" << endl;
	}

	void planificacion()
	{
		cout << "Aprensizaje: planificacion" << endl;
	}

	void produccion()
	{
		cout << "Aprensizaje: produccion" << endl;
	}

	void pruebasAceptacion()
	{
		cout << "Aprensizaje: pruebas de aceptacion" << endl;
	}
};

class Almacen{
private:
	queue <Videojuego*> eliminados;
	vector <Videojuego*> alm;
	int tamanio;

	//Almacen(){ instance = this; }
	//static Almacen* instance;

public:
	
	Almacen() {};
	/*static Almacen* getInstance()
	{
		if (instance != 0)
			return instance;
		else
		{
			Almacen();
			return instance;
		}
	}*/

	void creaInventario()
	{
		tamanio = 0;
		cout << "Almacen creado" << endl;
	}

	void agregaJuego() //Videojuego *temp con este parametro sirve
	{
		int op, op2;
		Videojuego * temp = NULL;
		string nombre, ext;
		double precio;
		long int serie;

		cout << "De que genero es el juego?" << endl
		<< "1) Estrategia" << endl
		<< "2) Aventura" << endl
		<< "3) Aprendizaje" << endl
		<< "4) Cancelar" << endl << endl;
		cin >> op;

		if (op == 1)
		{
			temp = new Estrategia;

			cout << "De que subgenero es?" << endl  //subgenero
				<< "1) Lucha" << endl
				<< "2) Estrategia" << endl << endl;
			cin >> op2;
			if (op2 == 1)
				temp->setSubGenero("lucha");
			else
				temp->setSubGenero("arcade");

			cout << "Quien es el desarrollador?" << endl;   //desarrollador
			cin >> ext;
			temp->setAtributoExtra(ext);
		}
		if (op == 2)
		{
			temp = new Aventura;
			cout << "De que subgenero es?" << endl
				<< "1) Plataforma" << endl
				<< "2) Aventura grafica" << endl << endl;
			cin >> op2;
			if (op2 == 1)//Subgenero
				temp->setSubGenero("plataforma");
			else
				temp->setSubGenero("grafica");

			cout << "Cual es el pais de origen?" << endl;   //pais de origen
			cin >> ext;
			temp->setAtributoExtra(ext);
		}
		if (op == 3)
		{
			temp = new Aprendizaje;

			cout << "De que subgenero es?" << endl
				<< "1) Idioma" << endl
				<< "2) Musica" << endl << endl;
			cin >> op;
			if (op == 1)
				temp->setSubGenero("idioma");
			else
				temp->setSubGenero("musica");

			cout << "En que idioma esta?" << endl;   //idioma
			cin >> ext;
			temp->setAtributoExtra(ext);
		}
		if (temp != NULL)
		{

			cout << "Cual es el nombre del juego?" << endl << endl; //nombre del juego
			cin >> nombre;
			temp->setNombre(nombre);

			cout << "Cual sera el precio del juego?" << endl << endl; //precio
			cin >> precio;
			temp->setPrecio(precio);

			cout << "Ingrese el numero de serie del juego" << endl << endl; //numero de serie
			cin >> serie;
			temp->setNumSerie(serie);

			alm.push_back(temp);
			tamanio++;
		}
	}

	void eliminarJuego()
	{
		long int tempSerie;
		string tempNombre;
		int opcion;
		int i = 0;

		cout << "Se eliminara por nombre o por numero de serie?" << endl
			<< "1) Nombre del videojuego" << endl
			<< "2) Numero de serie" << endl;
		cin >> opcion;
		if (opcion == 1)
		{
			cout << "Cual es el nombre del videojuego?" << endl;
			cin >> tempNombre;

			while (i < alm.size())
			{
				if (alm[i]->getNombre() == tempNombre)
				{
					if (eliminados.size() == 3)
						eliminados.pop();

					eliminados.push(alm[i]);
					alm.erase(alm.begin() + i);
					tamanio--;
				}
				i++;
			}
		}
		else
		{
			cout << "Cual es el numero de serie del videojuego" << endl;
			cin >> tempSerie;

			while (i < alm.size())
			{
				if (alm[i]->getNumSerie() == tempSerie)
				{
					if (eliminados.size() == 3) //para solo quedarnos con las ultimas 3 eliminaciones
						eliminados.pop();

					eliminados.push(alm[i]);
					alm.erase(alm.begin() + i);
					tamanio--;
				}
				i++;
			}
		}
	}

	void deshacer() //ultimas 3 operaciones
	{
		while (eliminados.size() > 0)
		{
			alm.push_back(eliminados.front());
			eliminados.pop();
			tamanio++;
		}
	}

	void ordenar() //de menor a mayor precio y viceversa
	{
		int op, index;
		Videojuego *temp;
		cout << "Como se ordenara el inventario?" << endl
			<< "1) De menor a mayor precio" << endl
			<< "2) De mayor a menor precio" << endl
			<< "3) Cancelar" << endl << endl;
		cin >> op;

		if (op == 1) //menor a mayor
		{
			for (int i = tamanio - 1; i >= 0; i--)//del final al inicio
			{
				temp = alm[i];
				index = i;

				for (int j = 0; j < i; j++) //buscamos el mayor para ponerlo al final
				{
					if (temp->getPrecio() < alm[j]->getPrecio())//precio mayor al que esta en temp
					{
						temp = alm[j];
						index = j;
					}
				}
				if (temp != alm[i])
				{
					alm[index] = alm[i];
					alm[i] = temp;
				}
			}
		}

		if (op == 2) //mayor a menor
		{
			for (int i = tamanio - 1; i >= 0; i--)//del final al inicio
			{
				temp = alm[i];
				index = i;

				for (int j = 0; j < i; j++) //buscamos el mayor para ponerlo al final
				{
					if (temp->getPrecio() > alm[j]->getPrecio())//precio menor al que esta en temp
					{
						temp = alm[j];
						index = j;
					}
				}
				if (temp != alm[i])
				{
					alm[index] = alm[i];
					alm[i] = temp;
				}
			}
		}
	}

	void buscarVideojuego() //por numero de serie o nombre
	{
		int tempSerie;
		string tempNombre;
		int opcion;
		int i = 0;

		cout << "Se buscara por nombre o por numero de serie?" << endl
			<< "1) Nombre del videojuego" << endl
			<< "2) Numero de serie" << endl << endl;
		cin >> opcion;
		if (opcion == 1)
		{
			cout << "Cual es el nombre del videojuego?" << endl << endl;
			cin >> tempNombre;

			while (i < alm.size())
			{
				if (alm[i]->getNombre() == tempNombre)
				{
					cout << "Nombre: " << alm[i]->getNombre() << endl
						<< " Precio: " << alm[i]->getPrecio() << endl
						<< " Subgenero: " << alm[i]->getSubGenero() << endl
						<< " Numero de Serie: " << alm[i]->getNumSerie() << endl
						<< " Informacion Extra: " << alm[i]->getAtributoExtra() << endl << endl;
				}
				i++;
			}
		}
		else
		{
			cout << "Cual es el numero de serie del videojuego" << endl << endl;
			cin >> tempSerie;

			while (i < alm.size())
			{
				if (alm[i]->getNumSerie() == tempSerie)
				{
					cout << "Nombre: " << alm[i]->getNombre() << endl
						<< " Precio: " << alm[i]->getPrecio() << endl
						<< " Subgenero: " << alm[i]->getSubGenero() << endl
						<< " Numero de Serie: " << alm[i]->getNumSerie() << endl
						<< " Informacion Extra: " << alm[i]->getAtributoExtra() << endl << endl;
				}
				i++;
			}
		}
	}

	void obtenerTotalElementos() //numero total de elementos en el inventario
	{
		cout << "Tenemos " << tamanio << " videojuegos en el inventario" << endl;
	}

	void imprimirInventario()
	{
		int i = 0;

		cout << endl << "INVENTARIO" << endl << endl;

		while (i < tamanio)
		{
			cout << "Nombre: " << alm[i]->getNombre() << endl
				<< "Precio: " << alm[i]->getPrecio() << endl
				<< "Subgenero: " << alm[i]->getSubGenero() << endl
				<< "Numero de Serie: " << alm[i]->getNumSerie() << endl
				<< "Informacion Extra: " << alm[i]->getAtributoExtra() << endl << endl;
			i++;
		}
		cout << endl;
	}

};

//Para singleton
//Almacen* Almacen::instance = 0;

int main()
{
	int op = 0;
	Almacen* al = NULL;

	/*Estrategia lu;
	lu.setNombre("lucha");
	lu.setNumSerie(123456789);
	lu.setPrecio(50.80);
	lu.setSubGenero("lucha");
	Videojuego *lu2 = lu.clonar();*/

	while (op != 9)
	{
		cout << "Que desea hacer?" << endl
			<< "1) Crear el almacen" << endl
			<< "2) Agregar un videojuego al inventario" << endl
			<< "3) Eliminar un juego del inventario" << endl
			<< "4) Deshacer los ultimas tres eliminaciones del inventario" << endl
			<< "5) Ordenar el inventario" << endl
			<< "6) Buscar un videojuego en el inventario" << endl
			<< "7) Obtener el total de elementos en el inventario" << endl
			<< "8) Imprimir el inventario" << endl
			<< "9) Salir" << endl << endl;
		cin >> op;

		if (op == 9)
			break;
		else if (al == NULL && op != 1)
			cout << "Primero se debe crear el almacen" << endl << endl;
		else
		{
			if (op == 1)
			{
				if (al == NULL)
				{
					al = new Almacen;
					al->creaInventario();
				}
				else
					cout << "El almacen ya se a creado" << endl << endl;
			}
			else if (op == 2)
				al->agregaJuego();
			else if (op == 3)
				al->eliminarJuego();
			else if (op == 4)
				al->deshacer();
			else if (op == 5)
				al->ordenar();
			else if (op == 6)
				al->buscarVideojuego();
			else if (op == 7)
				al->obtenerTotalElementos();
			else if (op == 8)
				al->imprimirInventario();
			else
				cout << "opcion no disponible" << endl << endl;
		}
	}

	return 0;
}