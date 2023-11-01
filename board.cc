// Board Class: Handles game state

//* TODO: Design user input
//* TODO: Rotation support


// Libararies
#include <iostream>
#include <map>
#include <utility>
#include "ship.hh"

// Env Vars
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

    // Private variables
    private:
        char board[BOARD_SIZE][BOARD_SIZE];
    
};


Board::Board()
{
    // Initialize board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE ; j++)
        {
            board[i][j] = ' ';
        }
    }
}


void Board::print_board()
{
    // Basic, content of board only (no legend)
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

void Board::place_ship(int x, int y, char direction, Ship ship)
{
    // Verify that the ship can be placed given location, direction, and ship length

    // Obtain theoretical ship placement
    std::map<int, int> ship_placement;
    for (int i = 0; i < ship.get_length(); i++)
    {
        if (direction == 'u')
        {
            ship_placement.insert(std::pair<int, int>(x - i, y));
        }
        else if (direction == 'd')
        {
            ship_placement.insert(std::pair<int, int>(x + i, y));
        }
        else if (direction == 'r')
        {
            ship_placement.insert(std::pair<int, int>(x, y + i));
        }
        else if (direction == 'l')
        {
            ship_placement.insert(std::pair<int, int>(x, y - i));
        }
    }



    
}

void Board::erase_board()
{
    // Erase board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE ; j++)
        {
            board[i][j] = ' ';
        }
    }
}
