#include <iostream>
#include <string>
#include <array>
#include <functional>
#include <vector>

using namespace std;

int main()
{

    cout << 15000 * 0.15 + 1000 * 0.3 << endl;

    array<float, 6> temperatures = {7, 14, 9, 8, 15, 10};

    cout << "temperatures\n";
    for (int i = 0; i < temperatures.size(); i++)
        cout << "temperature[" << i << "] " << temperatures[i] << endl;

    int k = 5;

    if (5 == k++)
        cout << "k=5" << endl;
    else
        cout << k << endl;

    k = 5;

    if (5 == ++k)
        cout << "k=5" << endl;
    else
        cout << k << endl;

    // pointers arithmetic
    int table[]{1, 2, 3, 4, 5};

    int nbElements = sizeof(table) / sizeof(int);

    for (int *p = table; p < table + nbElements; p++)
    {
        cout << *p << "   -  ";
    }
    cout << endl;

    // use helpers functions to initialize the pointers start/stop
    auto currentPointer = begin(table);
    auto endTable = end(table);

    for (; currentPointer != endTable; currentPointer++)
    {
        //values can be modified!!! e.g.  *currentPointer+=2 ....
        cout << *currentPointer << " ' ";
    }
    cout << endl;

    // extended for
    // values are COPIED, impossible to modify!!!!
    for (int val : table)
        cout << val << " _ ";

    cout << "\n\n";

    //vectors
    vector<int> v{2, 4, 6, 8};
    v.push_back(9);

    auto pVec = v.begin();
    for (; pVec != v.end(); ++pVec)
    {
        cout << *pVec << "  **  ";
    }
    cout << endl;

    //possible to modify on the fly
    pVec = v.begin();
    // pVec = v.cbegin();  // constant value   :-)
    for (; pVec != v.end(); ++pVec)
    {
        *pVec += 5;
        cout << *pVec << "  **  ";
    }
    cout << endl;

    //reverse
    for (auto p = v.rbegin(); p != v.rend(); ++p)
    {
        cout << *p << "-- ";
    }
    cout << endl;

    int idx = 0;
    while (table[idx] < 5)
    {
        cout << table[idx++] << " , ";
    }
    cout << endl;

    const char *training = "training C++";
    while (*training)
    {
        putchar(*training);
        training++;
    }
    cout << endl;

    // do  while loop

    const char *training2 = "development for arduino\n";

    do
    {
        putchar(*training2);
        training2++;

    } while (*training2);

    // break
    int i = 0;
    while (true)
    {
        cout << i << "   ";
        if (i == 10)
        {
            break;
        }
        i += 1;
    }

    //switch
    enum typeVAT
    {
        VAT0,
        VAT5,
        VAT20
    };

    typeVAT vat = typeVAT ::VAT5;
    float NoTaxPrice = 100;
    float TaxPrice;

    switch (vat)
    {
    case typeVAT::VAT0:
        TaxPrice = NoTaxPrice;
        break;

    case typeVAT::VAT5:
        TaxPrice = (float)(1.055 * NoTaxPrice);
        break;

    default:
        TaxPrice = (float)(1.2 * NoTaxPrice);
        break;
    }
    cout << "\n tax price " << TaxPrice << endl;

    cout << "\n\nnormal execution of the program!" << endl;
    return 0;
}