//* Board Class: Handles game state

// TODO: Design user input
// TODO: Rotation support


// Libararies
#include <array>
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

        /** Prints the board.
            @param: none
            @return: none
        */
        void print();

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
        char get(int x, int y);

        /** Erase the board
            @param: none
            @return: none
        */
        void erase();

    private:
        // Main board array
        char board[BOARD_SIZE][BOARD_SIZE];
    
};


Board::Board()
{
    // Initialize board with underscores
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE ; j++)
        {
            board[i][j] = '_';

        }
    }
}


void Board::print()
{
    // Print horizontal legend
    std::cout << "  0 1 2 3 4 5 6 7 8 9\n";

    // Print vertical legend and board content 
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // TODO: Enable letter legend once letter user input is implemented
        // std::cout << LETTER_LEGEND[i] << " ";
        std::cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Board::place_ship(int x, int y, char direction, Ship ship)
{
    // Verify that the ship can be placed given location, direction, and ship length

    // Obtain theoretical ship placement
    std::vector< std::pair<int, int> > ship_placement;


    for (int i = 0; i < ship.get_length(); i++)
    {
        if (direction == 'u')
        {
            ship_placement.insert(ship_placement.begin(),
                                  std::pair<int, int>(x, y - i));
        }
        else if (direction == 'd')
        {
            ship_placement.insert(ship_placement.begin(),
                                  std::pair<int, int>(x, y + i));
        }
        else if (direction == 'r')
        {
            ship_placement.insert(ship_placement.begin(),
                                  std::pair<int, int>(x + i, y));
        }
        else if (direction == 'l')
        {
            ship_placement.insert(ship_placement.begin(),
                                  std::pair<int, int>(x - i, y));
        }
        else
        {
            std::cout << "Invalid direction" << std::endl;
            return;
        }
    }

    // DEBUG: Print ship placement
    for (auto const& pair : ship_placement)
    {
        std::cout << pair.first << ", " << pair.second << std::endl;
    }

    // Verify if ship placement is valid
    for (auto const& pair : ship_placement)
    {
        if (pair.first < 0 || pair.first > BOARD_SIZE - 1 || pair.second < 0 ||
            pair.second > BOARD_SIZE - 1)
        {
            std::cout << "Invalid placement: Space(s) off board." << std::endl;
            return;
        }
        if (board[pair.second][pair.first] != '_')
        {
            std::cout << "Invalid placement: Space(s) occupied." << std::endl;
            return;
        }
    }

    // Place ship
    for (auto const& pair : ship_placement)
    {
        board[pair.second][pair.first] = ship.get_char_code();
    }

    std::cout << ship.get_name() << " successfully placed.\n";
}

void Board::erase()
{
    // Fill board with underscores
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE ; j++)
        {
            board[i][j] = '_';
        }
    }
}
