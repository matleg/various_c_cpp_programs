#include <iostream>
#include <vector>
#include <typeinfo>
#include <array>

using namespace std;

//lambda function
//format: [...](...) -> typeReturn {  }
// - [vEnv1, vEnv2, ...] - capture bloc, must be here even if empty
// - (param1, param2, ...) -  must be here even if empty
// typeReturn - trailing return type, if function returns a value or compiler cannot find the type automatically

int main()
{

    //lambda function
    auto computeTaxPrice = [](float noTaxPrice, float taxRate) { return noTaxPrice * (1. + taxRate); };
    cout << "type of variable returned " << typeid(computeTaxPrice).name() << endl;

    double fullPrice = computeTaxPrice(100, 0.2);
    cout << "computed price " << fullPrice << endl;

    //definition of a lambda function that captures an environment variable where it is executed
    int delta = 3;
    auto incByDelta = [delta](int a) { return a + delta; };

    cout << "10+" << delta << " = " << incByDelta(10) << endl;

    delta = 5;
    //lambda function captures the delta value when it is created
    //further changes are not taken into account
    cout << "10+" << delta << " = " << incByDelta(10) << endl;

    //environment variables  can be captured by their reference
    auto incByRefDelta = [&delta](int a) { return a + delta; };

    cout << "10+" << delta << " = " << incByRefDelta(10) << endl;

    delta = 7;
    //lambda function captures the delta value when it is created
    //further changes are not taken into account
    cout << "10+" << delta << " = " << incByRefDelta(10) << endl;

    // trailing return type example
    auto incByRefDelta2 = [&delta](int a) -> float { return a + delta; };

    auto result = incByRefDelta2(100);
    cout << "type of result " << typeid(result).name() << endl;

    // with several environment variables
    string name = "Jack";
    array<int, 2> tbAges = {5, 7};

    // lambda function
    auto displayDetails = [&tbAges, &name]() {
        cout << name << " has " << tbAges.size() << " children being " << tbAges[0] << "  aand  "
             << tbAges[1] << " year old." << endl;
    };

    displayDetails();

    //capture options
    // [=] - capture everything by copy  - modifications after are not seen by the lambda function
    // [&]  -  capture everything by value  - modification are seen
    //custom captures
    // [x, &y] capture x by copy and y by ref
    // [&, z] capture all by copy but z by ref

    cout << "\n\n  normal end of the program" << endl;
    return 0;
}