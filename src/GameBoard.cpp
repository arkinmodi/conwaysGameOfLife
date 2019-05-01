#include "GameBoard.h"

#include <stdexcept>
#include <iostream>

using namespace std;

/********************************** PRIVATE **********************************/

vector<vector<int>> BoardT::cellDeaths(vector<vector<int>> temp, int i, int j)
{
    temp.at(i).at(j) = Empty;
    int neighbors = 0;
    int x = 0, y = 0;
    for (int k = i - 1; k <= i + 1; k++)
    {
        for (int l = j - 1; l <= j + 1; l++)
        {
            x = k % 10;
            y = l % 10;
            if (k < 0)
            {
                x += 10;
            }
            if (l < 0)
            {
                y += 10;
            }
            if (x == i && y == j)
            {
                continue;
            }
            else if (this->S.at(x).at(y))
            {
                neighbors++;
            }
        }
    }
    if (neighbors == 2 || neighbors == 3)
    {
        temp.at(i).at(j) = Filled;
    }
    return temp;
}

vector<vector<int>> BoardT::cellBirths(vector<vector<int>> temp, int i, int j)
{
    int neighbors = 0;
    int x = 0, y = 0;
    for (int k = i - 1; k <= i + 1; k++)
    {
        for (int l = j - 1; l <= j + 1; l++)
        {
            x = k % 10;
            y = l % 10;
            if (k < 0)
            {
                x += 10;
            }
            if (l < 0)
            {
                y += 10;
            }
            if (x == i && y == j)
            {
                continue;
            }
            else if (this->S.at(x).at(y))
            {
                neighbors++;
            }
        }
    }
    if (neighbors == 3)
    {
        temp.at(i).at(j) = Filled;
    }
    return temp;
}

/********************************** PUBLIC ***********************************/

BoardT::BoardT(vector<int> s)
{
    if (s.size() != 100)
    {
        throw invalid_argument("BoardT: invalid_argument");
    }

    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 10; j++)
        {
            temp.push_back(s.at(k++));
        }
        this->S.push_back(temp);
    }
}

void BoardT::play(int n)
{
    vector<vector<int>> temp = this->S;
    while (n--)
    {
        for (unsigned int i = 0; i < this->S.size(); i++)
        {
            for (unsigned int j = 0; j < this->S.at(i).size(); j++)
            {
                if (this->S.at(i).at(j) == 1)
                {
                    temp = cellDeaths(temp, i, j);
                }
                else
                {
                    temp = cellBirths(temp, i, j);
                }
            }
        }
        this->S = temp;
    }
}

vector<vector<int>> BoardT::getBoard()
{
    return this->S;
}