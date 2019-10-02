#include "Person2.h"

class Employee : public Person2
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
