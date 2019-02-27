// C++ program to demonstrate differences between pointer
// and reference.

// from https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/

#include <iostream>
#include <stdio.h>
using namespace std;

struct demo
{
    int a;
};

int main()
{
    int x = 5;
    int y = 6;

    cout << "pointers and refs!" << x << endl;
    demo d;

    int *p;
    p = &x;

    int &r = x;
    // &r = y;				 // Compile Error
    r = y; // x value becomes 6

    // p = NULL;
    // &r = NULL;			 // Compile Error

    p++; // Points to next memory location
    r++; // x values becomes 7

    cout << "address of p " << &p << "   address of x " << &x << endl; // Different address
    cout << "address of r " << &r << "   value of x " << x << endl;    // Same address
    demo *q = &d;
    demo &qq = d;

    q->a = 8;
    // q.a = 8;				 // 5. Compile Error
    qq.a = 8;
    // qq->a = 8;			 // 5. Compile Error

    cout << "value of p " << p << endl; // 6. Prints the address
    cout << "value of r " << r << endl; // 6. Print the value of x

    return 0;
}
