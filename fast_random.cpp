#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

uint32_t state = 123456;

uint32_t getRandom()
{
    /* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
    uint32_t x = state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    state = x;
    return x;
}

int getRandomInt(int bound)
{
    return (getRandom() % bound);
}

int main()
{
    int tab[10] = {0};

    for (int i = 0; i < 1000; i++)
    {
        tab[getRandomInt(10)] += 1;
        cout << getRandomInt(10) << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << tab[i] << "   ";
    }
    cout << endl;
}
