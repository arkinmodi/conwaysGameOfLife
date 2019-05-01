/**
 *  \file Read.h
 *  \author Arkin Modi
 *  \brief Reads in the game data
 *  \date April 9, 2019
 */

#ifndef A4_READ_H_
#define A4_READ_H_

#include <vector>
#include <string>
#include "GameBoardTypes.h"

class Read
{
  private:
    static std::string read_input(std::string file);

  public:

    /**
     *  \brief Reads the input.txt file
     *  \return a list of CellT based on the input.txt file
     */
    static std::vector<int> load_data(std::string file);
};

#endif