#include <iostream>
#include <string>

using namespace std;

class Training
{
    string training;

    // from cppreference: 
    //  used to specify that the member does not affect the externally visible state of the class 
    // (as often used for mutexes, memo caches, lazy evaluation, and access instrumentation). 
    mutable int nbRequests = 0;

public:
    // constructor

    Training(string training)
    {
        this->training = training;
    }

    string GetInformation() const
    {
        //cannot modify field...
        //training = "new training";

        //...except if nbRequests is defined as mutable
        nbRequests++;

        return training + " has been requested " + to_string(nbRequests) + " times";
    }
};

int main()
{
    Training t("cpp");
    t.GetInformation();

    cout << t.GetInformation() << endl;
    cout << t.GetInformation() << endl;
    cout << t.GetInformation() << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}