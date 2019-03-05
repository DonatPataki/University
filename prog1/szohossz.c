#include <stdio.h>

int main()
{
    char line[1];
    scanf("%1023[^\n]", line);
    int bitek = 0;
    int szam = line[0];
    printf("\nBeolvasott char értéke intben: ");
    printf("%d\n",szam);
    while (szam != 0)
    {
        szam = szam >> 1;
        bitek++;
    }
    printf("%d", bitek);
    printf(" biten tárolható\n");
    return 0;
}
