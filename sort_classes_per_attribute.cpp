
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

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

bool speedCmp(Entity const &a, Entity const &b)
{
    if (a.speed == b.speed)
    {
        return a.x > b.x;
    };
    return a.speed < b.speed;
}

int main()
{

    Entity e1 = Entity(1, 2, 3.55);
    Entity e2 = Entity(4, 2, 3.55);
    Entity e3 = Entity(6, 3, 1.55);
    Entity e4 = Entity(-1, -2, 3.0);
    Entity e5 = Entity(0, 0, 1.8);

    Entity entities[] = {e1, e2, e3, e4, e5};

    cout << " before " << endl;
    for (Entity &e : entities)
    {
        e.printEntity();
    };

    std::sort(entities, entities + 5, speedCmp);

    cout << " after " << endl;
    for (Entity &e : entities)
    {
        e.printEntity();
    };
}
