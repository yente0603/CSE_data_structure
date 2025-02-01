#include <stdio.h>
typedef union
{
    unsigned long l;
    unsigned char c[4];
} x;
int main()
{
    x y;
    y.l = 0x12345678;
    if (y.c[0] == 0x78 && y.c[1] == 0x56 && y.c[2] == 0x34 && y.c[3] == 0x12)
        printf("little endian\n");
    else if (y.c[0] == 0x12 && y.c[1] == 0x34 && y.c[2] == 0x56 && y.c[3] == 0x78)
        printf("big endian\n");
    else
        printf("unknown\n");
    printf("address - 0x%lx:\n", y.l);
    for (int i = 0; i < 4; i++)
        printf("%p: 0x%02X\n", &y.c[i], y.c[i]);
}