#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

using namespace std;

// inline, all code in file .h

class Address
{
public:
    int no;
    string street;
    string city;

    //constructor
    Address(int no_, const string &street_, const string &city_) : no(no_), street(street_), city(city_)
    {
    }

    ~Address()
    {
        cout << "##### address deleted " << no << "  " << street << "  " << city << endl;
    }
};
