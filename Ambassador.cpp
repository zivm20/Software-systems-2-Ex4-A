#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Ambassador.hpp"

using namespace coup;
using namespace std;

Ambassador::Ambassador(Game& game, string name):Player(game,name){
    _role = "Ambassador";
}
void Ambassador::block(Player& player){
    if(player.role() == "Captain"){
        if(player.lastMove() == "steal"){
            /*
            game().getPlayer(player.target()).addCoins(2); 
            player.addCoins(-2);
            player.setTarget("");
            */
        }
    }
    throw runtime_error("Invalid Block!");
    
}




