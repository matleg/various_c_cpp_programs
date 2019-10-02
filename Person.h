#include <iostream>
#include <string>
#include <array>

using namespace std;

class Person
{

    //static : common to all instances
    static int lifeExpectancy;

    //private method
    int findAge() const; // const to be sure that age is not modified

    // define public fields of instances
public:
    string name_;

    int age;

    void WhoAmI();

    const static int Mr = 0;
    const static int Ms = 1;
    int civility;

    static int getLifeExpectancy();

    int getPersonLE();

    int getCivility();
};