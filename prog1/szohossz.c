#include <stdio.h>

int main()
{
    char line[1];
    scanf("%1023[^\n]", line);
    int bitek = 0;
    int szam = line[0];
    printf("\n");
    printf("%d\n",szam);
    while (szam != 0)
    {
        szam = szam >> 1;
        bitek++;
    }
    
    printf("%d\n", bitek);

    return 0;
}
