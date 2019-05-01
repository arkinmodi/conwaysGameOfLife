#include "Write.h"

#include <iostream>
#include <fstream>

using namespace std;

void Write::save_game(vector<vector<int>> s)
{
    ofstream outfile("output.txt");
    for (unsigned int i = 0; i < s.size(); i++)
    {
        vector<int> temp = s.at(i);
        for (unsigned int j = 0; j < temp.size(); j++)
        {
            char x = ' ';
            if (temp.at(j))
            {
                x = '#';
            }
            outfile << '[' << x << ']';
        }
            outfile << endl;
    }

    outfile.close();
}

void Write::print_game(vector<vector<int>> s)
{
    for (unsigned int i = 0; i < s.size(); i++)
    {
        vector<int> temp = s.at(i);
        for (unsigned int j = 0; j < temp.size(); j++)
        {
            char x = ' ';
            if (temp.at(j))
            {
                x = '#';
            }
            cout << '[' << x << ']';
        }
            cout << endl;
    }
}