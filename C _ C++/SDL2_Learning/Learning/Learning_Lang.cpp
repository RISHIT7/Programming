#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Player
{
private:
    int width;
    int height;
public:
    int health;

    Player(int w, int h)
    {
        width = w;
        height = h;
        health = 100;
    }

    int area() const {
        return width*height;
    }

    int get_health()
    {
        return health;
    }

};

template<typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    // Classes
    Player player_1 = Player(50, 50);
    cout<<player_1.get_health()<<endl;
    cout<<player_1.area()<<endl;

    // template
    int num_1 = max(3, 7);
    double num_2 = max(3.9, 7.7);

    // containers are just vectors and maps and stuff like that
    return 0;
}