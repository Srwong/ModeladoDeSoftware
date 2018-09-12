#include <iostream>
#include <vector>

struct A
{
	int x, y;

	A() = default;
	//A( x = 0) : x(x){}  sirve si lo llamas como A ejemplo();
	/*A() : x(10) //default construntor, default initialization
	{
		std::cout << "default constructor" << std::endl;
	}*/

	explicit A(int x, int y) : x(x), y(y)//Params contructor
	{
		std::cout << "Params constructor" << std::endl;
	}

	A(const A&)
	{
		std::cout << "copy constructor" << std::endl;
	}

	A(A&&)
	{
		std::cout << "move constructor" << std::endl;
	}

	A& operator =(A&&)
	{
		std::cout << "copy assignment move op" << std::endl;
	}
};

A llamaCopyConst(A a)
{
	A temp(a);
	//std::cout << "copy constructor" << std::endl;
	return temp;
}

A retA()
{
	A temp;
	return temp;
}

int main()
{
	/*A uno;
	A dos(3, 6);
	//A tres(dos);

	//llamaCopyConst(dos);
	A tres;*/

	std::vector<A> myVector;

	myVector.push_back(A(1, 2));

	//A a(A(1, 1)); //params
	A b;
	A a = std::move(b); //move constructor

}