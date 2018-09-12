//pasar el padre a singleton
//pasar a templates

#include <iostream>
#include <string>

using namespace std;

class Visitor;
class Number
{
protected:
   string quienSoy;
public:
   virtual void accept(Visitor*) = 0;
   virtual string getQuienSoy() {return quienSoy;}
};

class Integer : public Number
{
public:
   Integer()
   {
      quienSoy = "entero";
   }
   static int countInts;
   void accept(Visitor*);
};
int Integer::countInts = 0;

class Double : public Number
{
public:
   Double()
   {
      quienSoy = "double";
   }
   static int countDouble;
   void accept(Visitor*);
};
int Double::countDouble = 0;

//template <class T>
class Visitor
{
private:
  static Visitor* instance;
  Visitor()
  {
    instance = this;
  }
public:
  static Visitor* getInstance()
  {
    if(instance == 0)
      return new Visitor;
    return instance;
  }
   //un metodo sobrecargado por cada clase
   virtual void visit(Integer*) = 0;
   virtual void visit(Double*) = 0;
};
Visitor* Visitor::instance = 0;
//luego es una clase por cada funcion de las clases

class CountVisitor : public Visitor
{
public:
   //una funcion sobrecargada por cada clase
   void visit(Integer* i)
   {
      cout<<Integer::countInts<<endl;
   }
   void visit(Double* i)
   {
      cout<<Double::countDouble<<endl;
   }
};

class AddVisitor : public Visitor
{
public:
   void visit(Integer* i)
   {
      Integer::countInts++;
   }
   void visit(Double* i)
   {
      Double::countDouble++;
   }
};

class SubstractVisitor : public Visitor
{
   void visit(Integer* i)
   {
      Integer::countInts--;
   }
   void visit(Double* i)
   {
      Double::countDouble--;
   }
};

template <class T>
class PresentVisitor : public Visitor
{
public:
   void visit(T* i)
   {
      cout << i->getQuienSoy()<<endl;
   }
};

void Double::accept(Visitor* v)
{
   v->visit(this);
}

void Integer::accept(Visitor* v)
{
   v->visit(this);
}


int main()
{
   AddVisitor a;
   CountVisitor c;);
   PresentVisitor p;

   Number* n[] = { new Integer, new Double};

   for(int i = 0; i < 5; i++)
   {
      for(int j = 0; j < 2; j++)
      {
         n[j]->accept(a);
      }
   }

   //los parametros son las funciones a utilizar
   n[1]->accept(c);
   n[1]->accept(p);
   n[0]->accept(c);
   n[0]->accept(p);

   return 0;
}
