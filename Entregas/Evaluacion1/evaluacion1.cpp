//Manuel Hernandez
#include <iostream>
#include <string>
#include <vector>

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

	string getNombre() { return nombre; }
	double getPrecio() { return precio; }
	long int getNumSerie() { return numeroSerie; }
	string getSubGenero() { return subgenero; }

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
public:
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
};

//Plataforma y Gráfica
class Aventura : public ClonVideojuego < Aventura > {
public:
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
public:
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

//template <class T>
//Almacen* Almacen::instance = 0;

//template <class T>
class Almacen{
private:
	vector <Videojuego*> almacen;
	//int tamanioAlmacen;
	int elementos = 0;

	Almacen(){ instance = this; }
	static Almacen* instance;

public:
	
	static Almacen* getInstance()
	{
		if (instance != 0)
			return instance;
		else
		{
			Almacen();
			return instance;
		}
	}

	void creaInventario()
	{
		//cout << "De que tamanio debe ser el almacen?" << endl;
		//cin >> tamanioAlmacen;
		//almacen = new ClonVideojuego<T>[tamanioAlmacen]();
		cout << "Almacen creado" << endl;
	}

	void agregaJuego(Videojuego * temp)
	{
		/*if (elementos < almacen.size())
		{
		almacen[elementos] = *temp;
		elementos++;
		}
		else
		cout << "el almacen esta lleno, ho queda espacio " << endl;*/
		almacen.push_back(temp);
		elementos++;
	}

	void eliminarJuego()
	{
		int tempSerie;
		string tempNombre;
		int opcion;
		int i = 0;

		cout << "Se eliminara por nombre o por numero de serie?" << endl
			<< "1) Nombre del videojuego" << endl
			<< "2) Numero de serie" << endl;
		cin >> opcion;
		if (opcion = 1)
		{
			cout << "Cual es el nombre del videojuego?" << endl;
			cin >> tempNombre;

			while (i < almacen.size())
			{
				if (almacen[i]->getNombre() == tempNombre)
				{
					almacen.erase(almacen.begin() + i);
					elementos--;
				}
				i++;
			}
		}
		else
		{
			cout << "Cual es el numero de serie del videojuego" << endl;
			cin >> tempSerie;

			while (i < almacen.size())
			{
				if (almacen[i]->getNumSerie() == tempSerie)
				{
					almacen.erase(almacen.begin() + i);
					elementos--;
				}
				i++;
			}
		}
	}

	void deshacer() //ultimas 3 operaciones
	{

	}

	void ordenar() //de menor a mayor precio y viceversa
	{

	}

	void buscarVideojuego() //por numero de serie o nombre
	{
		int tempSerie;
		string tempNombre;
		int opcion;
		int i = 0;

		cout << "Se buscara por nombre o por numero de serie?" << endl
			<< "1) Nombre del videojuego" << endl
			<< "2) Numero de serie" << endl;
		cin >> opcion;
		if (opcion = 1)
		{
			cout << "Cual es el nombre del videojuego?" << endl;
			cin >> tempNombre;

			while (i < almacen.size())
			{
				if (almacen[i]->getNombre() == tempNombre)
				{
					cout << "el videojuego se encuentra en la posicion " << i << endl;
				}
				i++;
			}
		}
		else
		{
			cout << "Cual es el numero de serie del videojuego" << endl;
			cin >> tempSerie;

			while (i < almacen.size())
			{
				if (almacen[i]->getNumSerie() == tempSerie)
				{
					cout << "el videojuego se encuentra en la posicion " << i << endl;
				}
				i++;
			}
		}
	}

	void obtenerTotalElementos() //numero total de elementos en el inventario
	{
		cout << "Tenemos " << elementos << " videojuegos en el inventario" << endl;
	}

	void imprimirInventario()
	{
		int i = 0;

		cout << "INVENTARIO" << endl;
		while (i < elementos)
		{
			cout << almacen[i]->getNombre() << " " 
				<< almacen[i]->getNumSerie() << " " 
				<< almacen[i]->getPrecio() << " " 
				<< almacen[i]->getSubGenero() << endl;
			i++;
		}
		cout << endl;
	}

};

//template <class T>
Almacen* Almacen::instance = 0;

//template <class T>
int main()
{
	int op = 0;

	Estrategia lu;
	lu.setNombre("lucha");
	lu.setNumSerie(123456789);
	lu.setPrecio(50.80);
	lu.setSubGenero("lucha");

	Estrategia ar;
	ar.setNombre("arcade");
	ar.setNumSerie(987654321);
	ar.setPrecio(48.50);
	ar.setSubGenero("arcade");

	Videojuego *lu2 = lu.clonar();

	Aventura pl;
	Aventura gr;
	Aprendizaje mu;
	Aprendizaje id; 
	Almacen* al = Almacen::getInstance();
	while (op != 9)
	{
		cout << "Que desea hacer?" << endl
			<< "1) Crear el inventario" << endl
			<< "2) Agregar un videojuego al inventario" << endl
			<< "3) Eliminar un juego del inventario" << endl
			<< "4) Deshacer los ultimas tres eliminaciones del inventario" << endl
			<< "5) Ordenar el inventario" << endl
			<< "6) Buscar un videojuego en el inventario" << endl
			<< "7) Obtener el total de elementos en el inventario" << endl
			<< "8) Imprimir el inventario" << endl
			<< "9) Salir" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
			//Almacen* al = Almacen::getInstance();
			al->creaInventario();
			break;
		case 2:
			al->agregaJuego(&lu);
			break;
		case 3:
			al->eliminarJuego();
			break;
		case 4:
			al->deshacer();
			break;
		case 5:
			al->ordenar();
			break;
		case 6:
			al->buscarVideojuego();
			break;
		case 7:
			al->obtenerTotalElementos();
			break;
		case 8:
			al->imprimirInventario();
			break;
		default:
			cout << "opcion no disponible" << endl;
			break;
		}
	}
	
	return 0;
}