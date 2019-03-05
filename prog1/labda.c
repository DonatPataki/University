#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int x_max=159, y_max = 44, x = 0, y = 0, x_, y_;
    while(1)
    {
    	y_ = abs(y%y_max-y_max/2);
    	for (int i = 0; i < y_; i++)
    	{
    		printf("\n");
    	}
    	x_ = abs(x%x_max-x_max/2);
    	for (int i = 0; i < x_; i++)
    	{
    		printf(" ");
    	}
    	printf("*");
    	for (int i = y_; i < 23; i++)
    	{
    		printf("\n");
    	}
    	x++;
    	y++;
    	sleep(1);
    	
    }
}
