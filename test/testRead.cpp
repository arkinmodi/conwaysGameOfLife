#include "catch.h"
#include "Read.h"
#include <vector>
#include <fstream>

using namespace std;

static string getString(string file) {
    ifstream infile(file);
    string content(istreambuf_iterator<char>(infile), (std::istreambuf_iterator<char>()));
    content.erase(remove(content.begin(), content.end(), '\n'), content.end());
    content.erase(remove(content.begin(), content.end(), ']'), content.end());
    content.erase(remove(content.begin(), content.end(), '['), content.end());
    infile.close();
    return content;
}

static string toString(vector<int> x) {
    string content = "";
    for(unsigned int i = 0; i < x.size(); i++) {
        if(x.at(i) == 0) {
            content.append(" ");
        } else if (x.at(i) == 1) {
            content.append("#");
        }
    }
    return content;
}

TEST_CASE("tests for Read", "[Read]") {

    SECTION("exception test for load_data") {
        REQUIRE_THROWS_AS(Read::load_data(""), invalid_argument);
    }

    SECTION("general test for load_data") {

        // Tests all glider files
        for(int i = 1; i <= 5; i++) {
            string file = "test/glider/stage";
            file.append(to_string(i));
            file.append(".txt");
            string glider = getString(file);
            string test = toString(Read::load_data(file));
            REQUIRE(glider.compare(test) == 0);
        }

        // Tests all small_exploder files
        for(int i = 1; i <= 3; i++) {
            string file = "test/small_exploder/stage";
            file.append(to_string(i));
            file.append(".txt");
            string exploder = getString(file);
            string test = toString(Read::load_data(file));
            REQUIRE(exploder.compare(test) == 0);
        }
    }
}