#include "Read.h"

#include <fstream>
#include <streambuf>
#include <algorithm>

using namespace std;

string Read::read_input(string file)
{
    ifstream infile(file);
    string content(istreambuf_iterator<char>(infile), (std::istreambuf_iterator<char>()));
    content.erase(remove(content.begin(), content.end(), '\n'), content.end());
    content.erase(remove(content.begin(), content.end(), ']'), content.end());
    content.erase(remove(content.begin(), content.end(), '['), content.end());
    infile.close();
    return content;
};

vector<int> Read::load_data(string file)
{
    if (!ifstream(file).good())
    {
        throw invalid_argument("Read: file not found");
    }

    vector<int> cells;
    string data = read_input(file);

    for (unsigned int i = 0; i < data.size(); i++)
    {
        if (data[i] == '#')
        {
            cells.push_back(Filled);
        }
        else
        {
            cells.push_back(Empty);
        }
    }

    return cells;
};
