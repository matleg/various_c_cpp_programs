#include <iostream>
#include <string>
#include <array>
#include <typeinfo>
#include "Address.h"

using namespace std;

/*
3 kind of inheritance
- private
- public
- protected
*/

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

    Address *address;

    // constructor
    Person();
    Person(string name, int civility, int age);
    Person(string name, int civility, int age, int no, string street, string city);

    //destructor
    virtual ~Person();

    // constructor by copy
    Person(const Person &p); // const to prevent any modification of the person in argument

    // constructor by assignment of a copy. Override '=' operator
    Person &operator=(const Person &SourcePerson);
};

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

    if (address != nullptr)
        cout << "address " << address->no << ", " << address->street << ", " << address->city << endl;
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

//constructors

Person::Person()
{
    address = nullptr;
};

Person::Person(string name, int civility, int age_) : name_(name), civility(civility), age(age_)
{
    address = nullptr;
}

Person::Person(string name, int civility, int age, int no, string street, string city) : Person(name, civility, age)
{
    address = new Address(no, street, city);
}

//destructor

Person::~Person()
{
    cout << "----deleted " << this->name_ << endl;

    if (address)
        delete address;
}

//constructor by copy

Person::Person(const Person &pers) : age(pers.age), name_(pers.name_), civility(pers.civility)
{
    cout << " ++ constructor by copy " << endl;

    // new address with same infos

    auto *a = pers.address;

    address = new Address(a->no, (a->street) + " xXx ", a->city);
}

Person &Person::operator=(const Person &p)
{
    cout << " $$ $$ $$ constructor by copy assignment \n";
    name_ = p.name_;
    civility = p.civility;
    age = p.age;

    address = new Address(p.address->no, p.address->street, p.address->city);

    return *this;
}

class Employee : public Person
{
    //private fields
    int id;

    //public fields & methods
public:
    string service;

    // constructor

    Employee(const string &name, int civility, int age, int id_, const string &service_ = "")
        : Person(name, civility, age), id(id_), service(service_)
    {

        /*
        this -> id = id;
        this -> service = service;
        */
        //or use a list of values
    }
};

/*
 * constructor by copy
 * Person p2(p1);
 *
 * constructor of assignment by copy
 * Person p2
 * p2 = p1;
 *
 */

int main()
{

    string st2 = " Baker st";
    string ct2 = " London ";
    Person *p3 = new Person("Ann Lis", Person::Ms, 35);
    p3->address = new Address(1, st2, ct2);
    p3->WhoAmI();

    Person p8(*p3);
    p8.WhoAmI();

    Person p9 = Person("james bond", Person::Mr, 45, 33, "downing st", "Oxford");
    p9.WhoAmI();

    Person p10;
    p10 = p9; // operator overloaded !!!!!!

    p10.WhoAmI();

    Employee emp("Steve J", Person::Mr, 45, 12345, "Apple");

    emp.WhoAmI();

    auto displayPersonName = [](Person &p) {
        cout << p.name_ << endl;
    };

    displayPersonName(emp);

    //possible to put an employee into a person
    Person &pers = emp;
    //impossible to do the opposite
    //Employee &emp2 = pers;  // non const lvalue cannot bind to a value of unrelated type

    // 1st test : put in Employee the Person that contains an employee

    Employee &e = static_cast<Employee &>(pers);

    cout << "employe e service: " << e.service << endl;

    Employee &e2 = static_cast<Employee &>(p10);
    // cout << "employe e2 service: "<< e2.service  <<endl;  // does not work, no service attribute

    //Using dynamic cast, so that casting takes place at runtime and not compilation!!!
    //Error can be caught

    // dynamic casting - > object must have at least a virtual method

    Employee &e3 = dynamic_cast<Employee &>(pers); // person must be polymorphic (have virtual method)

    cout << "employe e3 service: " << e3.service << endl;

    try
    {
        Employee &e4 = dynamic_cast<Employee &>(p10);
        cout << "employe e4 service: " << e4.service << endl; // does not work, no service attribute
    }
    catch (exception &e)
    {
        cout << "dynamic cast failed :" << e.what() << endl;
    }

    // dynamic cast with pointer

    Employee *pe = dynamic_cast<Employee *>(&pers);
    cout << "pe service    " << pe->service << endl;

    cout << "\n\n\n end of the program" << endl;
    return 0;
}