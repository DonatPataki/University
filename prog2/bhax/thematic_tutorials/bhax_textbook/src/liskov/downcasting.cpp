#include <iostream>

class Base
{
public:
	void baseMethod()
	{
		std::cout << "Base funcion\n";
	}
};

class Derived : public Base
{
public:
	void derivedMethod()
	{
		std::cout << "Derived funcion\n";
	}
};

int main()
{
	Derived test;
	test.baseMethod();
	test.derivedMethod();
	Base* test1 = (Base*)&test;
	test1->baseMethod();
	//test1->derivedMethod(); //hibát okoz

	return 0;
}
