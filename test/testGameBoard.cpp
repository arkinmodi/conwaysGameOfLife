#include "catch.h"
#include "GameBoard.h"
#include "Read.h"
#include <vector>

using namespace std;

static bool isSame(vector<vector<int>> x, vector<int> y) {
    int k = 0;
    for(unsigned int i = 0; i < x.size(); i++) {
        for(unsigned int j = 0; j < x.at(i).size(); j++) {
            if(!(x.at(i).at(j) == y.at(k++))) {return false;}
        }
    }
    return true;
}

TEST_CASE("tests for GameBoard", "[GameBoard]") {
    // Setup
    vector<int> exploder1 = Read::load_data("test/small_exploder/stage1.txt");
    vector<int> exploder2 = Read::load_data("test/small_exploder/stage2.txt");
    vector<int> exploder3 = Read::load_data("test/small_exploder/stage3.txt");

    vector<int> glider1 = Read::load_data("test/glider/stage1.txt");
    vector<int> glider2 = Read::load_data("test/glider/stage2.txt");
    vector<int> glider3 = Read::load_data("test/glider/stage3.txt");
    vector<int> glider4 = Read::load_data("test/glider/stage4.txt");
    vector<int> glider5 = Read::load_data("test/glider/stage5.txt");

    SECTION("general test for BoardT") {
        BoardT testBoard1(exploder1);
        REQUIRE(isSame(testBoard1.getBoard(), exploder1));
        REQUIRE_FALSE(isSame(testBoard1.getBoard(), exploder2));
        REQUIRE_FALSE(isSame(testBoard1.getBoard(), exploder3));

        BoardT testBoard2(exploder2);
        REQUIRE(isSame(testBoard2.getBoard(), exploder2));
        REQUIRE_FALSE(isSame(testBoard2.getBoard(), exploder1));
        REQUIRE_FALSE(isSame(testBoard2.getBoard(), exploder3));

        BoardT testBoard3(exploder3);
        REQUIRE(isSame(testBoard3.getBoard(), exploder3));
        REQUIRE_FALSE(isSame(testBoard3.getBoard(), exploder1));
        REQUIRE_FALSE(isSame(testBoard3.getBoard(), exploder2));

        BoardT testBoard4(glider1);
        REQUIRE(isSame(testBoard4.getBoard(), glider1));
    }

    SECTION("exception test for BoardT") {
        vector<int> empty;
        glider1.pop_back();
        glider2.push_back(0);
        REQUIRE_THROWS_AS(BoardT(empty), invalid_argument);
        REQUIRE_THROWS_AS(BoardT(glider1), invalid_argument);
        REQUIRE_THROWS_AS(BoardT(glider2), invalid_argument);
    }

    SECTION("general test for play") {
        BoardT testBoard1(exploder1);
        testBoard1.play(1);
        REQUIRE(isSame(testBoard1.getBoard(), exploder2));

        BoardT testBoard2(exploder1);
        testBoard2.play(2);
        REQUIRE(isSame(testBoard2.getBoard(), exploder3));

        BoardT testBoard3(glider1);
        testBoard3.play(4);
        REQUIRE(isSame(testBoard3.getBoard(), glider5));
    }

    SECTION("general test for getBoard") {
        BoardT testBoard1(exploder1);
        REQUIRE(isSame(testBoard1.getBoard(), exploder1));
    }
}