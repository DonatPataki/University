#include <iostream>

int main()
{
    int a;
    int b;
    std::cout << "a értéke: ";
    std::cin >> a;
    std::cout << "b értéke: ";
    std::cin >> b;
    a+= b;
    b = a-b;
    a= a-b;
    std::cout << "a új értéke: " << a << "\nb új értéke: " << b;
}
