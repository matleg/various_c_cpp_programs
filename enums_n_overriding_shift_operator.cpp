#include <iostream>
#include <string>
#include <array>

using namespace std;

// C style enum
enum Color
{
    red,
    green,
    blue
};

// C style enum
enum Training
{
    cpp,
    python,
    angular
};

//C++ style

enum class StateExec
{
    Running,
    Stopped,
    Unknown
};

// can attach explicitly values
enum class Voltage : short
{
    Three = 3,
    Five = Three + 2,
    Nine = 9,
    Twelve = Three + Nine,
    fifteen,
    Unknown = -1

};

// enum with char
enum class evalExam : char
{
    Rejected = 'r',
    Good = 'g',
    Excellent = 'e'
};

// overriding insertion operator  <<   to print an eval item
ostream &operator<<(ostream &os, evalExam ev)
{
    switch (ev)
    {
    case evalExam ::Rejected:
        os << " you have been rejected";
        break;

    case evalExam ::Excellent:
        os << " very successfull";
        break;

    case evalExam ::Good:
        os << " mmmK ";
        break;

    default:
        os << " not available";
    }
}

int main()
{

    // enum color has defined a new type that cna be used

    Color col = Color::blue; // :: operator of resolution
    cout << "col " << col << endl;

    Color col2 = red; // without :: (C style)
    cout << "col2 " << col2 << endl;

    Training training = cpp;

    int i = 100;

    StateExec taskStatus = StateExec ::Stopped;

    //cout << " task status " << taskStatus << endl;
    // not possible to print as operator << is not overided byt the enum
    // cannot also be assigned to an int
    // i  = taskStatus

    // conversion enum to int
    i = static_cast<int>(taskStatus);
    cout << " i " << i << endl;

    // enum not specified
    Voltage v = Voltage ::fifteen;
    cout << "voltage " << static_cast<int>(v) << endl;

    // enum with char
    evalExam evaluation = evalExam ::Rejected;
    char c = static_cast<char>(evaluation);
    i = static_cast<int>(evaluation);

    cout << "evaluation  " << c << "    in int " << i << endl;

    // display eval
    cout << "evaluation  " << evaluation << endl;

    cout << "\n\n normal end of the program" << endl;
    return 0;
}