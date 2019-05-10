int
main (void)
{
    char line[1];
    scanf("%1023[^\n]", line);
    int bitek = 0;
    int szam = line[0];
    printf("\nBeolvasott char értéke intben: ");
    printf("%d\n",szam);
    
    unsigned long long int loops_per_sec = line[0];
    unsigned long long int ticks;

    printf ("Calibrating delay loop..");
    fflush (stdout);

    while ((loops_per_sec >>= 1) != -1)
    {
        
	bitek++;
        if (loops_per_sec == 0)
        {
    		printf("\nBeolvasott char értéke intben: ");
   		printf("%d\n",szam);
		printf("%d", bitek);
		printf(" biten tárolható\n");

            return 0;
        }
    }

    printf ("failed\n");
    return -1;
}
