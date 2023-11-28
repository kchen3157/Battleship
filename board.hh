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
        void print();


        /** Sets a char onto board
            @param: x
            @param: y
            @param: ship
            @return: int
        */
        int place_ship(int x, int y, char direction, Ship ship);

    
        /** Gets a char from board
            @param: x
            @param: y
            @return: char
        */
        char get(int x, int y);


        /** Erase the board
            @param: none
            @return: none
        */
        void erase();

    private:
        // Main board array
        char board[BOARD_SIZE][BOARD_SIZE];

        // List of ships currently on board
        std::vector<Ship> ship_list;
    
};

#endif // __BOARD_HH__
