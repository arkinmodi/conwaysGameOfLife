/**
 *  \file GameBoard.h
 *  \author Arkin Modi
 *  \brief Conway's Game of Life Game Board ADT
 *  \date April 9, 2019
 */

#ifndef A4_GAME_BOARD_H_
#define A4_GAME_BOARD_H_

#include "GameBoardTypes.h"
#include <vector>

class BoardT
{
private:
  std::vector<std::vector<int>> S;  // The Game Board
  std::vector<std::vector<int>> cellDeaths(std::vector<std::vector<int>> temp, int i, int j);
  std::vector<std::vector<int>> cellBirths(std::vector<std::vector<int>> temp, int i, int j);

public:

  /**
   *  \brief Constructs a new game board
   *  \param s The list of all cells statuses through an integer
   */
  BoardT(std::vector<int> s);

  /**
   *  \brief Iterates the game n stages forward
   *  \param n The number of stages to iterate
   */
  void play(int n);

  /**
   *  \brief Gets the game board
   *  \return The game board
   */
  std::vector<std::vector<int>> getBoard();
};

#endif