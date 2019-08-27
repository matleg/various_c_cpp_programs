#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <typeinfo>

using namespace std;

// variables allocation
// 2 ways to allocate memory used by a variable, ont the pile, on the heap

// global variable, defined outside the scope of all functions or classes --> on the HEAP

string *msg;

void f1()
{
    string message = "Hello\n";
    msg = &message;
}

void f2()
{
    // if info is heavy, better put it in the heap
    string *message2 = new string(" world"); // message2 is defined in the heap, not freed automatically
    // dynamic allocation, message2 contains the address where the object has been created

    // modification of global variable msg
    msg = message2;
}

void displaySize(array<int, 6> &tb)
{
    cout << "array has " << tb.size() << " element" << endl;
}

// template for a function having one generic parameter (n)
template <unsigned long n>           // long unsigned int n : definition of the generic parameter n, either long, either unsigned, either int.
void displaySize2(array<int, n> &tb) // pass by reference
{
    cout << "array has " << tb.size() << " element" << endl;
}

// template for 2 generic parameters. Generic argument T, defined with keyword "class"
template <class T, long unsigned int n> //
void displaySize3(array<T, n> &tb)
{
    cout << "array has " << tb.size() << " element" << endl;
}

int add(int a, int b)
{
    return a + b;
}

auto add2(int a, float b)
{
    return a + b;
}

// auto cannot infer type  as one return in float and the other is int
// developer has to define explicitly the single return type.
// syntax 'trailing return type' : -> int
auto add2_(int a, float b) -> int
{
    if (a + b < 10)
    {
        return a + b;
    }
    return (int)(a + b);
}

// template for addition to accept any type of data
template <class T, class U>
auto add3(T a, U b)
{
    return a + b;
}

void switchValues(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// overloading operator
void switchValues(int *pa, int *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

//function with default parameters
float computeTaxes(float noTaxPrice, float coefTaxes = 0.2f)
{
    return (1 + coefTaxes) * noTaxPrice;
}

//inline function
inline int multiply(int a, int b)
{
    return a * b;
}

// recursive
int factorial(int n)
{
    if (n <= 0)
    {
        throw n;
    }
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(int argc, char *argv[]) //   char* argv[] == char** argv
{

    f1();
    cout << *msg << endl; // message does not exist anymore

    for (int i = 0; i < argc; i++)
    {
        cout << "    arg " << i << ": " << argv[i] << endl;
    }

    f2();
    cout << *msg << endl;
    cout << msg << endl;

    //explicit delete of the object by the OS
    delete msg;
    cout << "!!!although deleted, can be displayed, think of removing the pointer!!!!! " << msg << endl;

    msg = nullptr;
    cout << "after deleting the pointer: " << msg << endl;
    cout << msg << endl;

    // array on the heap
    int *tb = new int[5];
    cout << "tb: " << tb << endl;

    for (int i = 0; i < 5; i++)
    {
        tb[i] = i + 1;
        cout << tb[i] << endl;
    }

    // if tb is not useful any more, free it
    delete[] tb; // !!!! delete tb; -->  only first element!!!
    tb = nullptr;
    cout << "tb " << tb << endl;

    array<int, 6> nb6 = {1, 2, 3, 4, 5, 6};
    displaySize(nb6);

    array<int, 3> nb3 = {1, 2, 3};
    // displaySize(nb3);  does not work for size 3 or different type (double...)
    // solution: build a template of function
    displaySize2(nb3);

    array<char, 4> tbChar = {'a', 'b', 'c', 'd'};
    displaySize3(tbChar);

    int v = add(2, 3);
    cout << "2+3=" << v << endl;

    // auto
    // for variables: type is inferred by compiler
    // for functions: specifies the return type

    auto a = 1 + 2.3;
    cout << "type of variable a is \"" << typeid(a).name() << "\" " << endl;

    //is a an integer
    if (typeid(a).name() == typeid(int).name())
    {
        cout << "a is type integer\n";
    }
    else if (typeid(a).name() == typeid(double).name())
    {
        cout << "a is type double\n";
    }

    auto b = {1, 2};
    cout << "b is type: " << typeid(b).name() << endl;

    int tbi[] = {1, 2};
    cout << "tbi is type: " << typeid(tbi).name() << endl;

    auto c = add2(4, 4.5);
    cout << "c is type:  " << typeid(c).name() << endl;

    auto d = add2_(4, 4.9);
    cout << "d is type:  " << typeid(d).name() << "  d=" << d << endl;

    auto e = add2(4.2, 4.5);
    cout << "e is type:  " << typeid(e).name() << "  e=" << e << endl;

    auto f = add3('a', 4); // a is 97 in dec format
    cout << "f is type:  " << typeid(f).name() << "  f=" << f << endl;

    auto g = add3(4.2, 5.3);
    cout << "g is type:  " << typeid(g).name() << "  g=" << g << endl;

    int i1 = 1;
    int i2 = 2;
    cout << "i1=" << i1 << ",  i2=" << i2 << endl;
    switchValues(i1, i2);
    cout << "i1=" << i1 << ",  i2=" << i2 << endl;
    switchValues(&i1, &i2);
    cout << "i1=" << i1 << ",  i2=" << i2 << endl;

    //inline function
    int h = multiply(2, 3);
    cout << "h = " << h << endl;

    // default param function
    float fullPrice = computeTaxes(100, 0.055);
    cout << "price for 100 with 5.5% taxes: " << fullPrice << endl;
    float fullPrice2 = computeTaxes(100);
    cout << "price for 100 with default taxes: " << fullPrice2 << endl;

    //recursive function
    cout << " factorial(5)=" << factorial(5) << endl;

    cout << "\n\nNormal end of the program" << endl;
    return 0;
}