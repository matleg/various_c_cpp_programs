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


    // if not friend, substitution failed as restricted access
    friend ostream &operator<<(ostream &os, Person &p)
    {
        os << " person : " << p.name_ << " , age " << p.age;
        if (p.address)
            os << " address : " << p.address->city;

        return os;
    }
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
    float wage;

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

    void setWage(float w)
    {
        wage = w;
    }

    int compareWage(Employee &e2)
    {
        if (wage == e2.wage)
            return 0;
        return wage < e2.wage ? -1 : 1;
    }

    friend int compareWages(Employee &e1, Employee &e2); // recognize signature everywhere

    //define as friend function the override of <<
    // this operator does not belong to the class, so override  must be declared friend
    friend ostream &operator<<(ostream &os, Employee &);

    friend class EmployeeFactory;
};

class EmployeeFactory
{
public:
    Employee createEmployer(int id, const string &name, int civility, int age, float wage)
    {
        Employee emp(name, civility, age, id);

        emp.wage = wage; // access possible as class is defined as friend

        return emp; // emp must by returned by copy, otherwise, it is lost
    }
};

int compareWages(Employee &e1, Employee &e2)
{
    if (e1.wage == e2.wage)
        return 0;
    return e1.wage < e2.wage ? -1 : 1;
}

//overriding operator << for employee class
ostream &operator<<(ostream &os, Employee &e)
{
    return os << "Employee id " << e.id << " , service: " << e.service << "  name :" << e.name_
              << "  , wage " << e.wage;
}

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

    // access to private member

    // emp.wage = 2000; //impossible to access

    emp.setWage(2000);

    Employee emp2("Bill G", Person::Mr, 60, 6541, "MCSFT");

    emp2.setWage(3000);

    int resultComparison = emp.compareWage(emp2);

    if (resultComparison < 0)
        cout << " emp1 earn less than emp2\n";
    else
        cout << " emp2 earn less or same as emp1\n";

    resultComparison = compareWages(emp2, emp);
    if (resultComparison < 0)
        cout << " emp1 earn less than emp2\n";
    else
        cout << " emp2 earn less or same as emp1\n";

    cout << emp << endl;

    // if not friend, substitution failed as restricted access
    cout << p10 << endl;

    // friend class

    EmployeeFactory fe;

    Employee emp3 = fe.createEmployer(777, "duke n ", Person::Mr, 50, 30000);
    cout << emp3 << endl;

    cout << "\n end of the program" << endl;
    return 0;
}