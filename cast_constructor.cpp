#include <iostream>
#include <typeinfo>
#include <array>
#include <string>

using namespace std;

class Defense
{

public:
    int grade;

    // constructor no args
    Defense()
    {
        grade = 0;
    }

    //converting constructor,
    // use of 'explicit' to avoid doing def = xx
    explicit Defense(int g)
    {
        if (g < 12)
            grade = g + 1;
        else
            grade = g;
    }
};

enum class Participation
{
    Enthousiastic,
    Active,
    Average,
    weak
};

class Exam
{

public:
    int grade;

    // constructor without args
    Exam()
    {
        grade = 0;
    }

    // converting constructor from int
    Exam(int g)
    {
        if (g < 10)
        {
            grade = g + 1;
        }
        else
        {
            grade = g;
        }
    } 
};

/* converting constructor
 * Exam exam(18);
 *
 * or
 *
 * Exam2 exam = 18; // cannot have implicit and explicit for the same class
 *
*/

int main()
{

    // implicit

    Exam exam = Exam(17);
    Exam exam2 = Exam(9);

    cout << exam2.grade << "    " << exam.grade << endl;

    // split declaration and init
    Exam exam4;
    cout << exam4.grade << endl;

    exam4 = 16; // this is implicit
    cout << exam4.grade << endl;

    // explicit
    cout << "explicit\n";

    Defense def = Defense(17); // this is explicit and still works
    Defense def2 = Defense(9);

    cout << def2.grade << "    " << def.grade << endl;

    // split declaration and init
    Defense def4;
    cout << exam4.grade << endl;

    //def4 = 16;  // this is implicit and will not work any more
    cout << def4.grade << endl;

    cout << "\n\n normal end of the program!" << endl;
    return 0;
}