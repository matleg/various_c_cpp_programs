#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;



// create template for stack type container

template <class T> class Pile
{
private:
    vector<T> content;

public:
    unsigned long size()
    {
        return content.size();
    }

    void push(T element)
    {
        content.push_back(element);
    }

    T pop()
    {
        T element = content.at(size()-1);
        content.pop_back();
        return  element;
    }

    bool isEmpty()
    {
        return size()==0;
    }

};



class Person
{
    string name;
    int year;

public:

    Person()
    {
        name = " name1 ";
        year = 1986;

    }

    Person(const string& n, int y)
    {
        name = n;
        year = y;
    }


    friend ostream& operator<<(ostream& os, Person p)
    {
        os << "name: " << p.name << " , year birth :" << p.year;
    }


};


int main()
{


    Pile <int> intPile;

    intPile.push(3);
    intPile.push(-3);
    intPile.push(-33);

    cout << "pile size :" << intPile.size() << endl;


    while (!intPile.isEmpty())
    {
        cout << "removing " << intPile.pop() << "  ";
    }


    Pile <Person> persPile;

    persPile.push(Person("toto", 2000));
    persPile.push(Person("titi", 1900));
    persPile.push(Person("tata", 1960));


    cout << "pile pers  size :" << persPile.size() << endl;


    while (!persPile.isEmpty())
    {
        cout << "removing " << persPile.pop() << "  ";
    }



    cout << "\n\n normal end of the program" << endl;
    return 0;
}