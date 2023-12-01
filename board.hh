#ifndef __BOARD_HH__
#define __BOARD_HH__

#include <iostream>
#include <map>
#include <utility>
#include "ship.hh"

// Env Vars
const int BOARD_SIZE = 10; // 10x10 board 
// const std::array<char, BOARD_SIZE> LETTER_LEGEND = {'A', 'B', 'C', 'D', 'E',
//                                                     'F', 'G', 'H', 'I', 'J'};


class Board
{
    public:

        // Constructor
        Board();

        /** Prints the main board.
            @param: none
            @return: none
        */
        void print_main();

        /** Prints the secondary board.
            @param: none
            @return: none
        */
        void print_secondary();


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


        /** Erase the main board
            @param: none
            @return: none
        */
        void erase_main();

        /** Erase the secondary board
            @param: none
            @return: none
        */
        void erase_secondary();

        /** Attack a coordinate on the board
            @param: x
            @param: y
            @param: ref_board
            @return: int
        */
        int attack(int x, int y, Board* opposing_board);

    private:
        // Main board array
        char board_main[BOARD_SIZE][BOARD_SIZE];
        // Secondary board array for attacks
        char board_secondary[BOARD_SIZE][BOARD_SIZE];

        // List of ships currently on board
        std::vector<Ship> ship_list;
    
};

#endif // __BOARD_HH__
