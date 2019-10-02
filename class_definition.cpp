#include <iostream>
#include "Person.h"
#include <typeinfo>

using namespace std;

void Person::WhoAmI()
{
    cout << typeid(this).name() << ": my name is " << name_ << "  and I am " << findAge() << "yo\n";
}

int Person::findAge() const
{
    return age; // method is declared const, impossible to modify anything
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

    p2->WhoAmI();

    delete (p2);

    cout << "\n\n\n end of the program" << endl;
    return 0;
}