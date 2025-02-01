#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void towers(int n, char A, char B, char C)
{
    if (n == 1)
        printf("disk 1 move form %c to %c\n", A, C);
    else
    {
        towers(n - 1, A, C, B);
        printf("disk %d move form %c to %c\n", n, A, C);
        towers(n - 1, B, A, C);
    }
}
int main(int argc, char **argv)
{
    int disk = atoi(argv[1]);
    // printf("%d\n", disk);
    time_t start, stop;
    start = time(NULL);
    towers(disk, 'A', 'B', 'C');
    stop = time(NULL);
    double duration = ((double)difftime(stop, start));
    printf("%lf", duration);
    return 0;
}
