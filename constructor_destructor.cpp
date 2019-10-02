#include <iostream>
#include "Person2.h"
#include <typeinfo>

void Person2::WhoAmI()
{
    string txtCivility;
    switch (civility)
    {
    case Mr:
        txtCivility = "mister";
        break;
    case Ms:
        txtCivility = "Miss";
        break;
    default:
        txtCivility = " nothing ";
    }

    cout << typeid(this).name() << ": my name is " << txtCivility << "  " << name_ << "  and I am " << findAge() << " y.o.\n";

    if (address != nullptr)
        cout << "address " << address->no << ", " << address->street << ", " << address->city << endl;
}

int Person2::findAge() const
{
    return age; // method is declared const, impossible to modify anything
}

int Person2::getLifeExpectancy()
{
    return lifeExpectancy;
}
int Person2::getPersonLE()
{
    if (civility == Person2::Mr)
        return Person2::getLifeExpectancy() - 5;
    return Person2::getLifeExpectancy() + 5;
}
int Person2::lifeExpectancy = 80;

int Person2::getCivility()
{
    return civility;
}

//constructors

Person2::Person2()
{
address = nullptr;
};


Person2::Person2(string name, int civility, int age_) : name_(name), civility(civility), age(age_)
{
    address = nullptr;
}

Person2::Person2(string name, int civility, int age, int no, string street, string city) : Person2(name, civility, age)
{
    address = new Address(no, street, city);
}

//destructor

Person2::~Person2()
{
    cout << "----deleted " << this->name_ << endl;

    if (address)
        delete address;
}

using namespace std;

int main()
{

    //on the pile
    Person2 p;

    if (typeid(p) == typeid(Person2))
    {
        cout << "same type \n";
    }

    p.name_ = "Jack Sparrow";
    p.age = 20;

    // use a member method
    p.WhoAmI();

    //on the heap
    auto *p2 = new Person2();

    if (typeid(*p2) == typeid(Person2))
    {
        cout << "same type \n";
    }

    p2->name_ = "Oliver twist";
    p2->age = 22;
    p2->civility = Person2::Ms;

    p2->WhoAmI();

    cout << " human " << Person2::getLifeExpectancy() << endl;

    cout << " O T  " << p2->getPersonLE() << endl;

    cout << " human from O T " << p2->getLifeExpectancy() << endl;

    string st = " baggend st";
    string ct = "hobbiton ";
    auto *addr = new Address(1, st, ct);

    p2->address = addr;
    p2->WhoAmI();

    delete (p2);

    string st2 = " Baker st";
    string ct2 = " London ";
    Person2 *p3 = new Person2("Ann Lis", Person2::Ms, 35);
    p3->address = new Address(1, st2, ct2);
    p3->WhoAmI();

    cout << "\n\n";

    Person2 p7("Cesar", Person2::Mr, 26, 32, "Rome St ", "Roma");
    p7.WhoAmI();

    cout << "\n\n\n end of the program" << endl;
    return 0;
}