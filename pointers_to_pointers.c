#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{   
    int age = 60;
    int *p_age = &age;

    printf("\naddress of age : %p\n", &age);
    printf("address of age : %p\n", p_age);

    printf("\nvalue of age : %d\n", *p_age);
    printf("value of age : %d\n", age);

    int **address_p_age = &p_age;
    printf("\naddress_p_age : %p\n", &p_age);
    printf("address_p_age : %p\n", address_p_age);
    
    printf("value at the address_p_age : %d\n", *address_p_age);  // decimal // == &age
    printf("value at the address of address_p_age : %p\n", **address_p_age);  // hexa // ==age
    
    return 0;
}

