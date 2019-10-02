#include <iostream>
#include "Person.h"
#include <typeinfo>

using namespace std;

void Person::WhoAmI()
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
}

int Person::findAge() const
{
    return age; // method is declared const, impossible to modify anything
}

int Person::getLifeExpectancy()
{
    return lifeExpectancy;
}
int Person::getPersonLE()
{
    if (civility == Person::Mr)
        return Person::getLifeExpectancy() - 5;
    return Person::getLifeExpectancy() + 5;
}
int Person::lifeExpectancy = 80;

int Person::getCivility()
{
    return civility;
}

int main()
{

    //on the pile
    Person p;

    if (typeid(p) == typeid(Person))
    {
        cout << "same type \n";
    }

    p.name_ = "Jack Sparrow";
    p.age = 20;

    // use a member method
    p.WhoAmI();

    //on the heap
    Person *p2 = new Person(); // or auto *p2 to modify name in one place only just in case

    if (typeid(*p2) == typeid(Person))
    {
        cout << "same type \n";
    }

    p2->name_ = "Oliver twist";
    p2->age = 22;
    p2->civility = Person::Ms;

    p2->WhoAmI();

    cout << " human " << Person::getLifeExpectancy() << endl;

    cout << " O T  " << p2->getPersonLE() << endl;

    cout << " human from O T " << p2->getLifeExpectancy() << endl;

    delete (p2);

    cout << "\n\n\n end of the program" << endl;
    return 0;
}