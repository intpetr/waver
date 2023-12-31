#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>


void plot(char * arr[], int stretch, int y)
{
    for (int i = 0;i<50;i++)
    {
        for (int j = 0;j<50;j++)
        {
            if (abs((sin(0.5*i)*stretch+14+y/4)-j)<1.5)
            {
                arr[i][j]='X';
            }
            else
            {
                arr[i][j]=' ';
            }
        }
    }
}


void printvis(char * arr[])
{
    for (int i = 0;i<50;i++)
    {
        for (int j = 0;j<50;j++)
        {
            if (j==49)
            {
                printf("%c |\n",arr[i][j]);
            }
            else
            {
                printf("%c ",arr[i][j]);
            }   
        }
    }
}

int main()
{

   int (*arrr)[8] = malloc(sizeof *arrr * 7);
   
   int r = 50, c = 50, i, j;
 
    char* arr[r];
    for (i = 0; i < r; i++)
        arr[i] = (char*)malloc(c * sizeof(char));



    int stretch = 2;
    bool desc = false;
    while (1)
    {
        
        plot(arr,stretch,stretch);
        printvis(arr);
        usleep(100000);

        if (desc)
        {
            stretch = stretch-1;
        }
        else if (desc == false)
        {
            stretch++;
        }

        if (abs(stretch) == 8)
        {
            desc = !desc;
        }
    }
}



