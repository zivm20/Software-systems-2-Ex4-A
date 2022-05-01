#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Contessa.hpp"

using namespace coup;
using namespace std;

Contessa::Contessa(Game& game, string name):Player(game,name){
    _role = "Contessa";
}