#include <iostream>

int main()
{
    int szam;
    std::cin >> szam;
    int bitek = 0;
    
    while (szam != 0)
    {
        szam = szam >> 1;
        bitek++;
    }
    
    std::cout << bitek << " biten tárolható.";

    return 0;
}
