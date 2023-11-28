//* Board Class: Handles game state


// Libraries
#include <array>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <ncurses.h>
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


Board::Board() : ship_list()
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
    printw("  0 1 2 3 4 5 6 7 8 9 X\n");

    // Print vertical legend and board content 
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // TODO: Enable letter legend once letter user input is implemented
        printw("%i ", i);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printw("%c ", board[i][j]);
        }
        printw("\n");
    }

    printw("Y\n");
}

int Board::place_ship(int x, int y, char direction, Ship ship)
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
            printw("Invalid direction\n");
            refresh();
            return -1;
        }
    }

    //* DEBUG: Print ship placement
    // for (const std::pair<int, int> &pair : ship_placement)
    // {
    //     std::cout << pair.first << ", " << pair.second << std::endl;
    // }

    // Verify if ship placement is valid
    for (const std::pair<int, int> &pair : ship_placement)
    {
        if (pair.first < 0 || pair.first > BOARD_SIZE - 1 || pair.second < 0 ||
            pair.second > BOARD_SIZE - 1)
        {
            printw("Invalid placement: Space(s) off-board.\n");
            refresh();
            return -1;
        }
        if (board[pair.second][pair.first] != '_')
        {
            printw("Invalid placement: Space(s) occupied.\n");
            refresh();
            return -1;
        }
    }

    // Place ship
    for (const std::pair<int, int> &pair : ship_placement)
    {
        board[pair.second][pair.first] = ship.get_char_code();
        ship.add_coordinate(pair);
    }

    // Save the ship to the ship list
    ship_list.push_back(ship);


    //* DEBUG: Print ship list
    // for (int i = 0; i < (int)(ship_list.size()); i++)
    // {
    //     std::cout << ship_list.at(i).get_name() << " @ [";
    //     std::vector<std::pair<int, int> > coord_list = ship_list.at(i).get_coordinates();

    //     for (int j = 0; j < (int)(coord_list.size()); j++)
    //     {
    //         std::cout << "(" << coord_list.at(j).first << ",";
    //         std::cout << coord_list.at(j).second << ") ";
    //     }
    //     std::cout << "]\n";
    // }

    // Inform user of successful placement
    printw("%s successfully placed @ (%d, %d)\n", ship.get_name().c_str(), x, y);

    return 0;
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
