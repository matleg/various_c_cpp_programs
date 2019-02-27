#include <iostream>

using namespace std;

int main()
{
    int test_array1[3][2] =
        {
            {2, 3},
            {4, 5},
            {6, 7}};

    cout << "array filled by hand\n";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << "test[" << i << "][" << j << "] = " << test_array1[i][j] << endl;
        }
    }

    int test_array2[3][2] = {0};

    cout << "array filled with 0s\n";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << "test[" << i << "][" << j << "] = " << test_array2[i][j] << endl;
        }
    }

    return 0;
}
