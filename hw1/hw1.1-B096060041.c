// Author: 李彥德 B096060041
// Date: 2023.09.08
// Purpose: to construct NxN magic square (N for odd)
#include <stdio.h>
#include <stdlib.h>
int main()
{
    for (int n = 1; n <= 9; n += 2) // for 1x1, 3x3, 5x5, 9x9 magic square
    {
        int matrix[9][9] = {0}; // initialize all number are 0
        int i = 0;              // i for x-axis of the matrix
        int j = (n - 1) / 2;    // j for y-axis of the matirx
        int x, y;               // to temporary store the data of i and j respectively
        matrix[i][j] = 1;

        for (int k = 2; k <= n * n; k++)
        {
            if (i - 1 < 0) // go upward
                x = n - 1;
            else
                x = i - 1;
            if (j - 1 < 0) // go left
                y = n - 1;
            else
                y = j - 1;
            if (matrix[x][y] != 0)
                i++;
            // if the data of matrix[x][y] are not equals to 0,which means there have another k on it
            // store k under k-1
            else
            {
                i = x;
                j = y;
            }
            matrix[i][j] = k;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                printf("%2d ", matrix[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
