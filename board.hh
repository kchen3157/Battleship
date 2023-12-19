#ifndef __BOARD_HH__
#define __BOARD_HH__

#include <iostream>
#include <map>
#include <utility>
#include "ship.hh"

// Env Vars
const int BOARD_SIZE = 10; // 10x10 board 

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

        /** Sets a ship onto the main board
            @param: int x
            @param: int y
            @param: char direction
            @param: Ship ship
            @return: int
        */
        int place_ship(int x, int y, char direction, Ship ship);

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
            @param: int x
            @param: int y
            @param: Board* opposing_board
            @return: int
        */
        int attack(int x, int y, Board* opposing_board, int player_num);

        /** Sets the main board to a given board
            @param: char board_main[BOARD_SIZE][BOARD_SIZE]
            @return: none
        */
        void set(char board_main[BOARD_SIZE][BOARD_SIZE]);

    private:
        // Main board array
        char board_main[BOARD_SIZE][BOARD_SIZE];
        // Secondary board array for attacks
        char board_secondary[BOARD_SIZE][BOARD_SIZE];

        // List of ships currently on board
        std::vector<Ship> ship_list;
    
};

#endif // __BOARD_HH__
