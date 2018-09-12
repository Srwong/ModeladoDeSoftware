#include <iostream>

using namespace std;

class Product
{
public:
	virtual void setUp() = 0;
};

class Prod1 : public Product
{
public:
	void setUp()
	{
		cout << "construccion del objeto complejo" << endl;
	}
};

class factoryMethod
{
protected:
	virtual Product* factoryMethod() = 0;
public:
	Product* create()
	{
		Product* p = factoryMethod();
		p->setUp();
		return p;
	}
};

class ConcreteFactoryOO :public factoryMethod//POO
{
	static Product* factoryMethod()
	{
		return new Prod1;
	}
};

int main()
{
	Product* p = ConcreteFactoryOO::factoryMethod();
}