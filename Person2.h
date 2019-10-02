#include <iostream>
#include <string>
#include <array>
#include "Address.h"


using namespace std;


#ifndef INC_08_CLASSES_PERSON_H
#define INC_08_CLASSES_PERSON_H


class Person2
{

    //static : common to all instances
    static int lifeExpectancy;

    //private method
    int findAge() const;  // const to be sure that age is not modified


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
        Person2();
        Person2(string name, int civility, int age);
        Person2(string name, int civility, int age, int no, string street, string city);


        //destructor
        ~Person2();



        // constructor by copy
        Person2(const Person2& p);   // const to prevent any modification of the person in argument

        // constructor by assignment of a copy. Override '=' operator
        Person2& operator = (const Person2& SourcePerson);





};


#endif //INC_08_CLASSES_PERSON_H
