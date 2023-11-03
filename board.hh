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

        // Constructor
        Board();

        /** Prints the board.
            @param: none
            @return: none
        */
        void print_board();


        /** Sets a char onto board
            @param: x
            @param: y
            @param: ship
            @return: none
        */
        void place_ship(int x, int y, char direction, Ship ship);

    
        /** Gets a char from board
            @param: x
            @param: y
            @return: char
        */
        char get_board(int x, int y);


        /** Erase the board
            @param: none
            @return: none
        */
        void erase_board();

    private:
        // Main board array
        char board[BOARD_SIZE][BOARD_SIZE];
    
};

#endif // __BOARD_HH__
