#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Game {
    public:
        string title;
        string category;
        double price;
    
        Game(string t, string c, double p) : title(t), category(c), price(p) {}
    };
