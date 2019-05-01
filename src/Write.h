/**
 *  \file Write.h
 *  \author Arkin Modi
 *  \brief Saves/Displays the game
 *  \date April 9, 2019
 */

#ifndef A4_WRITE_H_
#define A4_WRITE_H_

#include <vector>
#include "GameBoardTypes.h"
#include "GameBoard.h"

class Write
{
  private:
    
  public:

    /**
     *  \brief Saves the game by writing to the output.txt file
     *  \param s The game board to save
     */
    static void save_game(std::vector<std::vector<int>> s);

    /**
     *  \brief Displays the game board on the screen
     *  \param s The game board to display
     */
    static void print_game(std::vector<std::vector<int>> s);
};

#endif