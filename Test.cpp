#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace coup;

#include <string>
#include <algorithm>
using namespace std;




TEST_CASE("turns always continue") {
    Game game_1{};
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};
    CHECK("Moshe"==game_1.turn());
    duke.income();
    CHECK("Yossi"==game_1.turn());
    assassin.income();
    CHECK("Meirav"==game_1.turn());
    ambassador.income();
    CHECK("Reut"==game_1.turn());
    captain.income();
    CHECK("Gilad"==game_1.turn());
    contessa.income();
    CHECK("Moshe"==game_1.turn());

    //check that assassin can't coup with less than 3
    CHECK_THROWS(assassin.coup(ambassador));

    duke.foreign_aid();
    CHECK("Yossi"==game_1.turn());
    assassin.foreign_aid();
    CHECK("Meirav"==game_1.turn());
    ambassador.foreign_aid();
    CHECK("Reut"==game_1.turn());
    captain.foreign_aid();
    CHECK("Gilad"==game_1.turn());
    contessa.foreign_aid();
    CHECK("Moshe"==game_1.turn());
    
    duke.block(ambassador);
    duke.block(captain);
    duke.block(contessa);
    CHECK("Moshe"==game_1.turn());
    CHECK(duke.coins()==3);
    CHECK(ambassador.coins()==1);
    CHECK(captain.coins()==1);
    CHECK(contessa.coins()==1);
    duke.income();
    //assassin has 3
    CHECK_NOTHROW(assassin.coup(ambassador));
    CHECK("Reut"==game_1.turn());
    //cant block
    CHECK_THROWS(captain.block(assassin));
    //not enough coins
    CHECK_THROWS(captain.steal(assassin));
    //can block, doesn't have to be on her turn
    CHECK_NOTHROW(contessa.block(assassin));
    //still captains turn even after revival
    CHECK("Reut"==game_1.turn());


    
    
}
