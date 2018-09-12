//Manuel Alejandro Hernandez Peña A01022089
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Observador //clase apoyo
{
public:
    virtual void update(string frase) = 0;
};

class Sujeto //presidentes
{
private:
    string hablar;
    vector <Observador*> obs;
public:
     
    void aniadirObservador(Observador *obser)
    {
        obs.push_back(obser);
    }
    void decirAlgo(string oracion)
    {
    	hablar = oracion;
    	cout<<hablar<<endl;
    	informar();
    }
    string recordar()
    {
        return hablar;
    }
    void informar()
    {
        for (int i = 0; i < obs.size(); ++i)
          obs[i]->update(hablar);
    }
};

class Observadores : public Observador //televisoras
{
private:
    string comentado;
public:
    Observadores(Sujeto *persona)
    {
        persona->aniadirObservador(this);
        comentado = persona->recordar();
    }
    void update(string dicho)
    {
        comentado = dicho;
    }
    string cita()
    {
        return comentado;
    }
};

int main()
{
    Sujeto Nieto;
    Sujeto Trump;
    Sujeto Jlo;
    
    Observadores Reforma(&Nieto);
    Observadores Televisa(&Nieto);
    Observadores NBC(&Nieto);
    
    Trump.aniadirObservador(&Reforma);
    Trump.aniadirObservador(&Televisa);
    Trump.aniadirObservador(&NBC);
    
    Jlo.aniadirObservador(&Reforma);
    Jlo.aniadirObservador(&Televisa);
    Jlo.aniadirObservador(&NBC);
    
    Nieto.decirAlgo("Hola");
    
    cout<<Reforma.cita()<<endl;
    cout<<Televisa.cita()<<endl;
    cout<<NBC.cita()<<endl;
    
    Trump.decirAlgo("We need a wall");
    
    cout<<Reforma.cita()<<endl;
    cout<<Televisa.cita()<<endl;
    cout<<NBC.cita()<<endl;
    
    Jlo.decirAlgo("No se quien sea este :v");
    
    cout<<Reforma.cita()<<endl;
    cout<<Televisa.cita()<<endl;
    cout<<NBC.cita()<<endl;
    
    return 0;
}