#include <stdio.h>
#include <iostream>

int main()
{
    printf("Adjon meg egy decimális számot: ");
    int decimal;
    scanf("%d", &decimal);

    int i = 0;
    while(i != decimal)
    {
        std::cout << "1";
	i++;
    }

    

    return 0;
}
