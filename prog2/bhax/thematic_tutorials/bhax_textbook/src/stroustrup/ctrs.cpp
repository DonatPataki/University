#include <iostream>
#include <vector>

class example
{
private:
	int* ptr;
public:
	example(int a)
	{
		std::cout << "ctr\n";
		ptr = new int;
		*ptr = a;
	}

	~example()
	{
		delete ptr;
	}

	example(example& other)
	{
		std::cout << "cpy ctr\n";
		ptr = new int;
		*ptr = *other.ptr;
	}

	example(example&& other)
	{
		std::cout << "mv ctr\n";
		ptr = other.ptr;
		other.ptr = nullptr;
	}

	example& operator=(const example& other)
	{
		std::cout << "cpy assign\n";
		ptr = new int;
		*ptr = *other.ptr;
		return *this;
	}

	example& operator=(example&& other)
	{
		std::cout << "mv assign\n";
		ptr = other.ptr;
		other.ptr = nullptr;
		return *this;
	}

	void printValue()
	{
		std::cout << "Value of ptr: " << *ptr << std::endl;
	}
}; 

int main()
{
	std::vector<example> vec;
	example var1 = 10;
	example var2 = var1;
	vec.push_back(std::move(var2));
}
