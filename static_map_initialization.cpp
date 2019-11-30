#include <iostream>
#include <string>
#include <map>

using namespace std;

class Game
{
public:
    static map<string, int> initEntityMap()
    {
        map<string, int> m;
        m["Ball"] = 0;
        m["Player"] = 1;
        m["Referee"] = 2;
        return m;
    }
    const static map<string, int> entityMap;
};

const map<string, int> Game::entityMap = Game::initEntityMap();

Game game;

int main()
{

    cout << game.entityMap.at("Ball") << endl;
}