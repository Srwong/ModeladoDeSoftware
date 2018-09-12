//Manuel Alejandro Hernandez Peña A01022089
#include <iostream>
#include <string>

using namespace std;

class Spacecraft;
class Exploration;
class Colonization;
class Observation;
class Asteroid;
class Stony;
class Iron;
class Planet;
class Desert;
class Earth;

class Asteroid
{
protected:
    string st;
public: 
    virtual void collision(Spacecraft * s)=0;
    virtual void collision(Planet * p)=0;
    virtual void collision(Stony * a)=0;
    virtual void collision(Iron * a)=0;
    
    template <class T>
    static T* getInstance()
    {
        static T v;
        return &v;
    }
    
    string getSt()
    {
        return st;
    }
};

class Stony : public Asteroid
{
public:
    Stony()
    {
        st = "Soy un meteorito de piedra :v";
    }
    void collision(Spacecraft * s);
    void collision(Planet *p);
    void collision(Stony * a);
    void collision(Iron * a);
};

class Iron : public Asteroid
{
public:
  Iron()
  {
    st = "Soy un meteorito de hierro";
  }
  void collision(Spacecraft * s);
  void collision(Planet *p);
  void collision(Stony * a);
  void collision(Iron * a);
};


class Planet
{
protected:
    string st;
public: 
    template <class T>
    static T* getInstance()
    {
        static T v;
        return &v;
    }
    
    virtual void collision(Spacecraft * s) = 0;
    virtual void collision(Stony * c) = 0;
    virtual void collision(Iron * c) = 0;
    virtual void collision(Desert * p) = 0;
    virtual void collision(Earth * p) = 0;
    string getSt()
    {
        return st;
    }
};

class Desert : public Planet
{
public:
    Desert()
    {
        st = "soy un planeta desierto";
    }
    
    void collision(Spacecraft * s);
    
    void collision(Stony * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
     void collision(Iron * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    void collision(Desert * p);
    void collision(Earth * p);
};

class Earth : public Planet
{
public:
    Earth()
    {
        st = "soy un planeta de tierra";
    }
    
    void collision(Spacecraft * s);
    
    void collision(Stony * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
     void collision(Iron * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    
    void collision(Desert * p);
    void collision(Earth * p);
};


class Spacecraft
{
protected:
    string st;
public: 
    template <class T>
    static T* getInstance()
    {
        static T v;
        return &v;
    }
    
    virtual void collision(Stony * c) = 0;
    virtual void collision(Iron * c) = 0;
    virtual void collision(Desert * c) = 0;
    virtual void collision(Earth * c) = 0;
    virtual void collision(Exploration * s)=0;
    virtual void collision(Colonization * s)=0;
    virtual void collision(Observation * s)=0;
    string getSt()
    {
        return st;
    }
};

class Exploration : public Spacecraft
{
public:
    Exploration()
    {
        st = "Soy una nave de exploracion";
    }
    void collision(Stony * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    void collision(Iron * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    void collision(Desert * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    void collision(Earth * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    
    void collision(Exploration * s);
    void collision(Colonization * s);
    void collision(Observation * s);
};

class Colonization : public Spacecraft
{
public:
    Colonization()
    {
        st = "Soy una nave de colonizacion";
    }
    void collision(Stony * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    void collision(Iron * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    void collision(Desert * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    void collision(Earth * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    
    void collision(Exploration * s);
    void collision(Colonization * s);
    void collision(Observation * s);
};

class Observation : public Spacecraft
{
public:
    Observation()
    {
        st = "Soy una nave de observacion";
    }
    void collision(Stony * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    void collision(Iron * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    void collision(Desert * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    void collision(Earth * c)
    {
        cout<<st<<" colisiono con "<< c->getSt()<<endl;
    }
    
    void collision(Exploration * s);
    void collision(Colonization * s);
    void collision(Observation * s);
};

void Stony::collision(Spacecraft * s)
{
    s->collision(this);
}
void Stony::collision(Planet * p)
{
    p->collision(this);
}
void Iron::collision(Spacecraft * s)
{
    s->collision(this);
}
void Iron::collision(Planet * p)
{
    p->collision(this);
}


void Desert::collision(Spacecraft * s)
{
    s -> collision(this);
}

void Earth::collision(Spacecraft * s)
{
    s -> collision(this);
}

void Exploration::collision(Exploration * s)
    {
        cout<<st<<" colisiono con "<<s->getSt()<<endl;
    }
void Exploration::collision(Colonization * s)
    {
        cout<<st<<" colisiono con "<<s->getSt()<<endl;
    }
void Exploration::collision(Observation * s)
    {
        cout<<st<<" colisiono con "<<s->getSt()<<endl;
    }
    
void Observation::collision(Exploration * s)
    {
        cout<<st<<" colisiono con "<<s->getSt()<<endl;
    }
void Observation::collision(Colonization * s)
    {
        cout<<st<<" colisiono con "<<s->getSt()<<endl;
    }
void Observation::collision(Observation * s)
    {
        cout<<st<<" colisiono con "<<s->getSt()<<endl;
    }
    
void Colonization::collision(Exploration * s)
    {
        cout<<st<<" colisiono con "<<s->getSt()<<endl;
    }
void Colonization::collision(Colonization * s)
    {
        cout<<st<<" colisiono con "<<s->getSt()<<endl;
    }
void Colonization::collision(Observation * s)
    {
        cout<<st<<" colisiono con "<<s->getSt()<<endl;
    }
    
void Desert::collision(Desert * p)
{
    cout<<st<<" colisiono con "<<p->getSt()<<endl;
}
void Desert::collision(Earth * p)
{
    cout<<st<<" colisiono con "<<p->getSt()<<endl;
}
void Earth::collision(Desert * p)
{
    cout<<st<<" colisiono con "<<p->getSt()<<endl;
}
void Earth::collision(Earth * p)
{
    cout<<st<<" colisiono con "<<p->getSt()<<endl;
}

void Stony::collision(Stony * a)
{
    cout<<st<<" colisiono con "<<a->getSt()<<endl;
}
void Stony::collision(Iron * a)
{
    cout<<st<<" colisiono con "<<a->getSt()<<endl;
}

void Iron::collision(Stony * a)
{
    cout<<st<<" colisiono con "<<a->getSt()<<endl;
}
void Iron::collision(Iron * a)
{
    cout<<st<<" colisiono con "<<a->getSt()<<endl;
}
int main()
{
    //naves
    Exploration* ex = Spacecraft::getInstance<Exploration>();
    Colonization* col = Spacecraft::getInstance<Colonization>();
    Observation* ob = Spacecraft::getInstance<Observation>();
    //asteroides
    Stony* ston = Asteroid::getInstance<Stony>();
    Iron* ir = Asteroid::getInstance<Iron>();
    //Planetas
    Desert* des = Planet::getInstance<Desert>();
    Earth* ea= Planet::getInstance<Earth>();
    
    //exploracion
    ston->collision(ex);
    ir->collision(ex);
    des->collision(ex);
    ea->collision(ex);
    //colonizacion
    ston->collision(col);
    ir->collision(col);
    des->collision(col);
    ea->collision(col);
    //observacion
    ston->collision(ob);
    ir->collision(ob);
    des->collision(ob);
    ea->collision(ob);
    
    //planetas contra asteroide
    des->collision(ston);
    des->collision(ir);
    ea->collision(ston);
    ea->collision(ir);
    //asteroide contra planeta
    ston->collision(des);
    ston->collision(ea);
    ir->collision(des);
    ir->collision(ea);
    //naves con naves
    ex->collision(col);
    ex->collision(ob);
    ex->collision(ex);
    
    col->collision(ex);
    col->collision(col);
    col->collision(ob);
    
    ob->collision(ex);
    ob->collision(col);
    ob->collision(ob);
    
    //Planetas
    des->collision(ea);
    des->collision(des);
    ea->collision(ea);
    ea->collision(des);
    
    //asteroides
    ston->collision(ston);
    ston->collision(ir);
    ir->collision(ston);
    ir->collision(ir);
    return 0;
}
