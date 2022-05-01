#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Captain.hpp"

using namespace coup;
using namespace std;

Captain::Captain(Game& game, string name):Player(game,name){
    _role = "Captain";
}