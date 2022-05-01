#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"

using namespace coup;
using namespace std;

Game::Game():_players(),curr_turn(0){
}
vector<string> Game::players(){
    vector<string> names;
    for(string p:_players){
        names.push_back(p);
    }
    return names;
}
void Game::addPlayer(string p){
    _players.push_back(p);
}
string Game::turn(){
    return _players[curr_turn];
}
string Game::Winner(){
    vector<string> active_players = players();
    if(active_players.size() > 1){
        throw runtime_error("Game hasn't ended yet!");
    }
    return active_players[0];
}
string Game::getPlayer(string name){
    for(string p: _players){
        if(name == p){
            return p;
        }
    }
    throw runtime_error("Player doesn't exist!");
}
void Game::nextTurn(){
    curr_turn = (curr_turn+1)%_players.size();
}