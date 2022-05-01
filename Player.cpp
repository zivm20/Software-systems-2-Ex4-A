#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Player.hpp"

using namespace coup;
using namespace std;

Player::Player(Game& game, string name): _game(game), _name(name),_role(""),_coins(0),_lastMove(""),_target(""),_alive(true){
    _game.addPlayer(_name);
}
void Player::valid_move(){
    if(coins() >= 10){
        throw runtime_error("Must use coup with 10 or more coins");
    }
    if(_game.turn() != name()){
        throw runtime_error("It's not "+name()+"'s turn");
    }
}
void Player::income(){
    valid_move();
    _coins++;
    end_turn("income","");
}
void Player::end_turn(string move, string target){
    _target=target;
    _lastMove = move;
    _game.nextTurn();
}

