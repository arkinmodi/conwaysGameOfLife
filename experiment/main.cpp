#include "Read.h"
#include "GameBoardTypes.h"
#include "GameBoard.h"
#include "Write.h"

#include <iostream>
using namespace std;

int main()
{
    BoardT game(Read::load_data("input.txt"));
    Write::save_game(game.getBoard());

    for (int i = 0; i < 16; i++)
    {
        game.play(1);
        Write::print_game(game.getBoard());
        cout << endl;
    }
    Write::save_game(game.getBoard());
    return 0;
};