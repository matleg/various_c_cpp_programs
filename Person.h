#include <iostream>
#include <string>
#include <array>


using namespace std;


#ifndef INC_08_CLASSES_PERSON_H
#define INC_08_CLASSES_PERSON_H


class Person
{
    //private method
    int findAge() const;  // const to be sure that age is not modified


    // define public fields of instances
    public:
        string name_;

        int age;

        void WhoAmI();



};


#endif //INC_08_CLASSES_PERSON_H
