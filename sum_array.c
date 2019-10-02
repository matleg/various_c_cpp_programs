#include <stdio.h>
#include <stdlib.h>

void sumArray(int tab[], int n); // Prototype de fonction

int main(int argc, char *argv[])

{
    int tab[6]= {14,20,40,1,3,4};
    sumArray(tab, 6);
    return 0;
}

void sumArray(int tab[], int n)

{

    int res=0;
    int j;
    for (j=0;j<n;j++)
    {
        res += tab[j];
    }
    printf("%d \n",res);

}
