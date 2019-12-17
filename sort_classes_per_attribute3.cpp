
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// sorting using a vector and lambda function
// from: https://stackoverflow.com/questions/5122804/how-to-sort-with-a-lambda

class Entity
{
public:
    Entity();
    Entity(double x_, double y_, float speed_) : x(x_), y(y_), speed(speed_){};

    float speed;
    double x, y;

    void printEntity()
    {
        cout << "x:" << x << "   y:" << y << "  velocity:" << speed << endl;
    }
};

int main()
{
    Entity e1 = Entity(1, 2, 3.55);
    Entity e2 = Entity(4, 2, 3.55);
    Entity e3 = Entity(6, 3, 1.55);
    Entity e4 = Entity(-1, -2, 3.0);
    Entity e5 = Entity(0, 0, 1.8);

    vector<Entity> entities = {e1, e2, e3, e4, e5};

    cout << " before " << endl;
    for (Entity &e : entities)
    {
        e.printEntity();
    }

    // descending order
    sort(entities.begin(), entities.end(), [](const Entity &a, const Entity &b) -> bool { return a.speed > b.speed; });

    cout << " descending " << endl;
    for (Entity &e : entities)
    {
        e.printEntity();
    }

    // ascending order
    sort(entities.begin(), entities.end(), [](const Entity &a, const Entity &b) -> bool { return a.speed < b.speed; });

    cout << " ascending " << endl;
    for (Entity &e : entities)
    {
        e.printEntity();
    }
}
