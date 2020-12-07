#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{

    map<string, int> ordered;
    ordered["hello"] = 1;
    ordered["world"] = 2;
    for (auto &p : ordered)
        cout << p.first << p.second << endl;
    cout << "ordered map size:" << ordered.size() << endl
         << endl;

    unordered_map<string, int> unordered;
    unordered["hello"] = 3;
    for (auto &p : unordered)
        cout << p.first << p.second << endl;
    cout << "unordered map size:" << unordered.size() << endl
         << endl;

    set<int> _s;
    _s.insert(543);
    _s.insert(123);
    if (_s.find(123) != _s.end())
        cout << "found: 123" << endl;
    cout << "set size:" << _s.size() << endl
         << endl;

    unordered_set<int> unordered_s;
    unordered_s.insert(123);
    if (unordered_s.find(123) != unordered_s.end())
        unordered_s.erase(123);
    cout << "unordered set size:" << unordered_s.size() << endl
         << endl;
}