#include <iostream>
#include <string>
#include <array>
#include <functional>

using namespace std;

struct Size
{

    int length, width, height;

    function<int()> perimeter = [this]() { return 4 * (this->length + this->width + this->height); };

    // field containing a lambda function defined in the constructor
    function<int()> surface;

    // field containing a lambda function defined elsewhere
    function<int()> volume; // < return type, parameters >

    // define a constructor
    // special method that has the type name (struct or class), has no return type
    // an explicit constructor "hides" the default constructor (which has no arguments) !!! /!
    Size(int length, int width)
    {
        this->length = length;
        this->width = width;
        this->height = 1;

        surface = [this]() { return 2 * (this->width * this->length + this->height * this->length + this->height * this->width); };
    }

    /*
    Size(int length, int width, int h)
    {
        this->length = length;
        this->width = width;
        this->height = h;

        surface = [this](){return 2*(this->width * this->length
                           + this->height* this->length
                           + this->height*this->width);};
    }
     */

    // need to define a constructor without arguments

    Size()
    {
        this->length = 1;
        this->width = 1;
        this->height = 1;
    }

    // instantiation form another constructor
    Size(int length, int width, int h) : Size(length, width)
    {
        this->height = h;
    }

    // also classical functions
    float computeBasePerimeter()
    {
        return 2 * this->length + 2 * this->width;
    }
};

//override insertion operator for struct Size
ostream &operator<<(ostream &outFlux, Size t)
{
    outFlux << "size: " << t.length << "  width " << t.width << "  height " << t.height;
}

int main()
{

    // create a struct on the pile
    Size size{20, 10, 5};

    Size size2 = {5, 1, 4};

    // initialize the field volume
    size.volume = [size]() { return size.height * size.width * size.length; }; 

    Size size3; // constructor with no args
    cout << "perimeter with default init  " << size3.computeBasePerimeter() << endl;

    cout << size << endl;
    cout << size3 << endl;

    // Size instance on the heap
    Size *psize = new Size();

    psize->height = 2;
    psize->width = 2;
    psize->length = 2;

    cout << *psize << endl;
    cout << (typeid(size3).name() == typeid(Size).name()) << endl;

    // deleting heap
    delete psize;
    cout << "psize  " << psize << "   " << *psize << endl;
    
    psize = nullptr;
    // now segfault
    // cout << "psize  "  << psize << "   " << *psize << endl;

    cout << "\n\n normal end of the program" << endl;
    return 0;
}