#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Assassin.hpp"

using namespace coup;
using namespace std;

Assassin::Assassin(Game& game, string name):Player(game,name){
    _role = "Assassin";
}