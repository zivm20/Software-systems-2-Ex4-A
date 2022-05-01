#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Duke.hpp"

using namespace coup;
using namespace std;

Duke::Duke(Game& game, string name):Player(game,name){
    _role = "Duke";
}
