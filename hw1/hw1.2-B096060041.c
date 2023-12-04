// Author: 李彥德 Lee Yen Te B096060041
// Date: 2023.09.08
// Purpose: print 1! to N! (N factorial), N greater then 0, less then 50
#include <stdio.h>
#include <stdlib.h>
#define size 100 // the size of the array
int main()
{
    int x;
    while (1)
    {
        scanf(" %d", &x);
        if (x > 0)
        {
            int f[size] = {0}; // initialize all number are 0
            f[0] = 1;          // initialize 1!=1
            int i, j;

            for (i = 1; i <= x; i++) // i for x
            {
                for (j = 0; j < size; j++)
                    f[j] *= i; // all elements multiple i(x)
                for (j = 0; j < size; j++)
                {
                    if (f[j] > 9) // to judge that whether one element to store only one digit (0 to 9) or not
                    {
                        f[j + 1] += (f[j] / 10);
                        f[j] %= 10;
                    }
                }

                // output
                printf("%d!=", i);
                for (j = size - 1; j >= 0; j--)
                {
                    if (f[j] != 0) // determine that meaningless 0 while not be displayed
                    {
                        printf("%d", f[j]);
                        break;
                    }
                }
                for (int k = j - 1; k >= 0; k--)
                    printf("%d", f[k]);
                printf("\n");
            }
            printf("\n");
        }
        else
            return 0;
    }
}