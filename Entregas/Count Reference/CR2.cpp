//Manuel Alejandro Hernandez Pena A01022089

#include <iostream>
using namespace std;

class Counter 
{
protected:
   int cont;
public:
   Counter()
   {
      cont = 1;
   }
   
   void increase()
   {
      cont++;
   }
   
   void decrease()
   {
      cont--;
   }
   
   ~Counter()
   {
      delete this;
   }
};

class Child : public Counter
{
public:
   int *p;
   Child()
   {
      p = new int;
   }
   ~Child()
   {
      if(cont == 1)
      {
         delete p;
      }
      decrease();
      p = NULL;
   }
   Child getObject()
   {
      increase();
      return *this;
   }
};

int main()
{
   Child a;
   Child b = a.getObject();
   *(a.p) = 5;
   cout << *(b.p) <<endl;
}
