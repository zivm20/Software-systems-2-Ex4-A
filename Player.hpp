
#include <string>
#include <iostream>
#include <stdexcept>
#include "Game.hpp"
#pragma once
namespace coup{
    class Player{
        
        protected:
            std::string _role;
            int _coins;
            std::string _name;
            std::string _lastMove;
            std::string _target;
            bool _alive;
            Game _game;

        public:
            Player(Game& game, std::string name);
            void income();
            void foreign_aid(){}
            virtual void coup(Player& player){}
            virtual void block(Player& player){}

            inline int coins(){
                return _coins;
            }
            inline std::string role() const{ 
                return _role;
            }
            inline std::string name() const{
                return _name;
            }
            inline std::string lastMove() const{
                return _lastMove;
            }
            inline Game game() const{
                return _game;
            }
            inline std::string target() const{
                return _target;
            }
            inline bool isAlive(){
                return _alive;
            }
            inline void addCoins(int n){
                _coins+=n;
            }
            inline void setTarget(std::string s){
                _target = s;
            }
            
            void valid_move();
            void end_turn(std::string move, std::string target);
    };
}