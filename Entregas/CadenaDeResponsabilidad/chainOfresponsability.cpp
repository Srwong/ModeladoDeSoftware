//Manuel Alejandro Hernandez Peña
//te dan dominio regresa ip
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class ManejadorMensaje{
    
protected:
    ManejadorMensaje* proximo = NULL;
public:
    void establecerProximo(ManejadorMensaje *prox)
    {
        proximo = prox;
    }
    virtual string manejarMensaje(string url) = 0;
    //virtual void asignarDirecciones(map <string, string> m) = 0;
};

//10 inventadas cada uno o 2 bonitas cada 1
//5 servidores
class ServidorA : public ManejadorMensaje{
private:
    map<string, string> direcciones;
public:
    ServidorA()
    {
        direcciones["google.com"] = "216.58.201.142";
        direcciones["youtube.com"] = "216.58.201.142";
    }
    
    string manejarMensaje(string url)
    {
        map<string, string>::iterator it; //creamos un iterador
        it = direcciones.find(url); //buscamos la url;
        if(it != direcciones.end())
       {
           cout<<"Se encontro en el servidor A"<<endl;
           return direcciones[url]; //si lo encontro regresamos el contenido
       }
        else
        { //en caso de no encontrarlo vamos al que le sigue
            if(proximo != NULL) //checamos si existe un sucesor
            return proximo->manejarMensaje(url); //si existe le pedimos que lo busque con lo que el tiene
        }
        
        return "No se encontro"; //si el ultimo no lo tiene le regresa a todos que no se encontro
    }
    
   /* void asignarDirecciones(map <string, string> m)
    {
        direcciones = m;
    }*/
};

class ServidorB : public ManejadorMensaje{
private:
    map<string, string> direcciones;
public:
    ServidorB()
    {
        direcciones["facebook.com"] = "31.13.66.36";
        direcciones["reddit.com"] = "151.101.65.140";
    }
    string manejarMensaje(string url)
    {
        map<string, string>::iterator it; //creamos un iterador
        it = direcciones.find(url); //buscamos la url;
        if(it != direcciones.end())
        {
           cout<<"Se encontro en el servidor B"<<endl;
           return direcciones[url]; //si lo encontro regresamos el contenido
       }
        else
        { //en caso de no encontrarlo vamos al que le sigue
            if(proximo != NULL) //checamos si existe un sucesor
            return proximo->manejarMensaje(url); //si existe le pedimos que lo busque con lo que el tiene
        }
        
        return "No se encontro"; //si el ultimo no lo tiene le regresa a todos que no se encontro
    }
    
   /* void asignarDirecciones(map <string, string> m)
    {
        direcciones = m;
    }*/
};

class ServidorC : public ManejadorMensaje{
private:
    map<string, string> direcciones;
public:
    ServidorC()
    {
        direcciones["cplusplus.com"] = "167.114.170.15";
        direcciones["miscursos.tec.mx"] = "200.34.203.30";
    }
    string manejarMensaje(string url)
    {
        map<string, string>::iterator it; //creamos un iterador
        it = direcciones.find(url); //buscamos la url;
        if(it != direcciones.end())
        {
           cout<<"Se encontro en el servidor C"<<endl;
           return direcciones[url]; //si lo encontro regresamos el contenido
       }
        else
        { //en caso de no encontrarlo vamos al que le sigue
            if(proximo != NULL) //checamos si existe un sucesor
            return proximo->manejarMensaje(url); //si existe le pedimos que lo busque con lo que el tiene
        }
        
        return "No se encontro"; //si el ultimo no lo tiene le regresa a todos que no se encontro
    }
    
   /* void asignarDirecciones(map <string, string> m)
    {
        direcciones = m;
    }*/
};

class ServidorD : public ManejadorMensaje{
private:
    map<string, string> direcciones;
public:
    ServidorD()
    {
        direcciones["yahoo.com"] = "206.190.36.45";
        direcciones["cdmon.com"] = "46.16.56.21";
    }
    string manejarMensaje(string url)
    {
        map<string, string>::iterator it; //creamos un iterador
        it = direcciones.find(url); //buscamos la url;
        if(it != direcciones.end())
        {
           cout<<"Se encontro en el servidor D"<<endl;
           return direcciones[url]; //si lo encontro regresamos el contenido
       }
        else
        { //en caso de no encontrarlo vamos al que le sigue
            if(proximo != NULL) //checamos si existe un sucesor
            return proximo->manejarMensaje(url); //si existe le pedimos que lo busque con lo que el tiene
        }
        
        return "No se encontro"; //si el ultimo no lo tiene le regresa a todos que no se encontro
    }
    
   /* void asignarDirecciones(map <string, string> m)
    {
        direcciones = m;
    }*/
};

class ServidorE : public ManejadorMensaje{
private:
    map<string, string> direcciones;
public:
    ServidorE()
    {
        direcciones["platinumgod.co.uk"] = "178.62.0.156";
        direcciones["netflix.com"] = "52.16.225.224";
    }
    string manejarMensaje(string url)
    {
        map<string, string>::iterator it; //creamos un iterador
        it = direcciones.find(url); //buscamos la url;
        if(it != direcciones.end())
        {
           cout<<"Se encontro en el servidor E"<<endl;
           return direcciones[url]; //si lo encontro regresamos el contenido
       }
        else
        { //en caso de no encontrarlo vamos al que le sigue
            if(proximo != NULL) //checamos si existe un sucesor
            return proximo->manejarMensaje(url); //si existe le pedimos que lo busque con lo que el tiene
        }
        
        return "No se encontro"; //si el ultimo no lo tiene le regresa a todos que no se encontro
    }
    
   /* void asignarDirecciones(map <string, string> m)
    {
        direcciones = m;
    }*/
};

int main()
{
    ServidorA* A = new ServidorA;
    ServidorB* B = new ServidorB;
    ServidorC* C = new ServidorC;
    ServidorD* D = new ServidorD;
    ServidorE* E = new ServidorE;
     
    A->establecerProximo(B);
    B->establecerProximo(C);
    C->establecerProximo(D);
    D->establecerProximo(E);
    
    string dir;
    cout<<"Ingrese una direccion (ejemplo: google.com):"<<endl;
    cin >> dir;
    
    string res = A->manejarMensaje(dir);
    cout<<res<<endl;
    /*string res = A->manejarMensaje("google.com");
    cout<<res<<endl;
    
    res = A->manejarMensaje("facebook.com");
    cout<<res<<endl;
    
    res = A->manejarMensaje("miscursos.tec.mx");
    cout<<res<<endl;
    
    res = A->manejarMensaje("yahoo.com");
    cout<<res<<endl;
    
    res = A->manejarMensaje("netflix.com");
    cout<<res<<endl; */
    return 0;
}