// from https://stackoverflow.com/questions/1640258/need-a-fast-random-generator-for-c

#include <stdio.h>

unsigned int g_seed = 123456;

void fast_srand(int seed)
{
    g_seed = seed;
}
int fastrand()
{
    //fastrand routine returns one integer, similar output value range as C lib.
    g_seed = (214013 * g_seed + 2531011);
    return (g_seed >> 16) & 0x7FFF;
}
int fastRandInt(int maxSize)
{
    return fastrand() % maxSize;
}

int main()
{

    for (int r = 0; r < 100; r++)
    {
        int m = fastRandInt(10);
        printf("%d", m);
    };
}
