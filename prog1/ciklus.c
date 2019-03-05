//gcc ciklus.c -o ciklus -fopenmp
#include <unistd.h>
#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    switch(*argv[1])
    {
        case '0':
        while(1)
        {
            sleep(1);
        }
        break;

        case '1':
        while(1)
        {

        }
        break;

        case '2':
        while(1)
        {
            #pragma omp parallel for
            for(int i = 0; i < 999999; i++)
            {

            }
        }
        break;
    }
    return 0;
}
