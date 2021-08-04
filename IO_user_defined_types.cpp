#include <iostream>
#include "string"

using namespace std;

// from "A tour of C++, B. Stroustrup"

class Entry
{
public:
    string name;
    int number;
};

// output operator
ostream &operator<<(ostream &os, const Entry &e)
{
    return os << e.name << " " << e.number << ".";
}

// input operator
istream &operator>>(istream &is, Entry &e)
//read {"name", number} pair
{
    char c, c2;
    if (is >> c && c == '{' && is >> c2 && c2 == '"')
    {
        string name;
        while (is.get(c) && c != '"')
        {
            name += c;
        }

        if (is >> c && c == ',')
        {
            int number = 0;
            if (is >> number >> c && c == '}')
            {
                e = {name, number};
                return is;
            }
        }
    }
    is.setstate(ios_base::failbit);
    return is;
}

int main()
{
    // to type :
    //{"john Marwood Clee", 123456   }"
    //{"michael jack", 987654}"

    for (Entry ee; cin>>ee;)
    {
        cout << ee<< endl;
    }

    return 0;
}