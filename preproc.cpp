#include <bits/stdc++.h>

using namespace std;

#define VARIADIC(Param, ...) Param(__VA_ARGS__)
#define VARIADIC2(POne, PTwo, PThree, ...) POne(PThree, __VA_ARGS__, PTwo)

#define PRINT(x) printf("variable : " #x " = %d \n", variable##x)

#define debug(msg) fputs(__FILE__ ":" num2str(__LINE__) " - " msg "\n", stdout)
#define num2str(x) str(x)
#define str(x) #x

void some_func(int a, int b, int c, int d)
{
    cout << a << ",  " << b << ",  " << c << ",  " << d << endl;
}

int main()
{
    VARIADIC(printf, "%d \n", 8);
    // Compiler sees: printf("%d \n", 8);

    VARIADIC2(some_func, 3, 8, 6, 9);
    // Compiler sees: some_func(8, 6, 9, 3);

    int variableY = 15;
    PRINT(Y);
    // compiler sees
    // printf("variable : ""Y"" = %d", variableY);

    debug("toto");

    return 0;
}
