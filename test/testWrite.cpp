#include "catch.h"
#include "Read.h"
#include "GameBoard.h"
#include "Write.h"

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

static bool isSame(string file) {

    // Load in manually created file
    ifstream infile(file);
    string correct(istreambuf_iterator<char>(infile), (std::istreambuf_iterator<char>()));
    infile.close();

    // Load in generated file
    ifstream testFile("output.txt");
    string test(istreambuf_iterator<char>(testFile), (std::istreambuf_iterator<char>()));
    testFile.close();

    return correct.compare(test) == 0;
}

TEST_CASE("tests for Write", "[Write]") {
    BoardT glider1(Read::load_data("test/glider/stage1.txt"));

    SECTION ("general test for save_game") {
        Write::save_game(glider1.getBoard());
        REQUIRE(isSame("test/glider/stage1.txt"));
    }

    SECTION("manual test for print_game") {

        // Load in manually created file
        ifstream infile("test/glider/stage1.txt");
        string correct(istreambuf_iterator<char>(infile), (std::istreambuf_iterator<char>()));
        infile.close();

        cout << endl << "MANUAL TEST" << endl << endl;
        cout << "Expected Result:" << endl;
        cout << correct << endl;
        cout << "Actual Result:" << endl;
        Write::print_game(glider1.getBoard());
    }
}