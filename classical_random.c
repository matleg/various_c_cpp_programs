#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


int main(int argc,const char *argv[])

{
    srand(0);  // seed
    /* or : 
    int seed;
    seed = time(NULL);  // seconds since Jan 1, 1970
    srand(seed);
    */

    printf("rand int between 0 and 4:\n");
    for (int i=0; i<20; i++)
    {
        printf("%d ",rand()%5);
    }

    printf("\n\nrand int :\n");
    
    for (int i=0; i<20; i++)
    {
        printf("%d ",rand());
    }

    printf("\n RAND_MAX value: %d \n:", RAND_MAX);

    printf("\n\nrand between 0 and 1 inclusive :\n");
    
    for (int i=0; i<20; i++)
    {
        printf("%f ", (double)rand() / (double)RAND_MAX );
    }

    


}
