#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char *argv[])
{
    int aa = 0, bb = 90;

    int *pa = &aa;
    int *pb = &bb;

    printf("a %d   b %d \n", *pa, *pb);
    
    swap(pa, pb);
    printf("a %d   b %d \n", *pa, *pb);

    // or
    swap(&aa, &bb);
    printf("a %d   b %d \n", *pa, *pb);

    return 0;
}
