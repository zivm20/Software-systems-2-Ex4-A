#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#pragma once
namespace coup{
    
    class Game{
        private:
            std::vector<std::string> _players;
            size_t curr_turn;
        
        public:
            Game();
            std::vector<std::string> players();
            void addPlayer(std::string p);
            std::string getPlayer(std::string name);
            std::string turn();
            std::string Winner();
            void nextTurn();
            
    };
}

