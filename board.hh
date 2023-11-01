#ifndef __BOARD_HH__
#define __BOARD_HH__

#include <iostream>
#include <map>
#include <utility>
#include "ship.hh"

const int BOARD_SIZE = 10;


class Board
{
    public:
        Board();

        void print_board();

        void place_ship(int x, int y, char direction, Ship ship);

    
        char get_board(int x, int y);


        void erase_board();

    private:
        char board[BOARD_SIZE][BOARD_SIZE];
    
};

#endif // __BOARD_HH__
