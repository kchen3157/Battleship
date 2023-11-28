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
            @return: none
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
        int attack(int x, int y, Board* ref_board);

    private:
        // Main board array
        char board_main[BOARD_SIZE][BOARD_SIZE];
        // Secondary board array for attacks
        char board_secondary[BOARD_SIZE][BOARD_SIZE];

        // List of ships currently on board
        std::vector<Ship> ship_list;
    
};


Board::Board() : ship_list()
{
    // Initialize boards with underscores
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE ; j++)
        {
            board_main[i][j] = '_';
            board_secondary[i][j] = '_';
        }
    }
}


void Board::print_main()
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
            printw("%c ", board_main[i][j]);
        }
        printw("\n");
    }

    printw("Y\n");
}

void Board::print_secondary()
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
            printw("%c ", board_secondary[i][j]);
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
        if (board_main[pair.second][pair.first] != '_')
        {
            printw("Invalid placement: Space(s) occupied.\n");
            refresh();
            return -1;
        }
    }

    // Place ship
    for (const std::pair<int, int> &pair : ship_placement)
    {
        board_main[pair.second][pair.first] = ship.get_char_code();
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

void Board::erase_main()
{
    // Fill board with underscores
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE ; j++)
        {
            board_main[i][j] = '_';
        }
    }
}

void Board::erase_secondary()
{
    // Fill board with underscores
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE ; j++)
        {
            board_secondary[i][j] = '_';
        }
    }
}


int Board::attack(int x, int y, Board* opposing_board)
{
    // Check if attack is valid
    if (x < 0 || x > BOARD_SIZE - 1 || y < 0 || y > BOARD_SIZE - 1)
    {
        printw("Invalid attack: Space off-board.\n");
        refresh();
        return -1;
    }
    if (board_secondary[y][x] != '_')
    {
        printw("Invalid attack: Space already attacked.\n");
        refresh();
        return -1;
    }

    if (opposing_board->board_main[y][x] != '_') // If successful attack
    {
        // Mark secondary board
        board_secondary[y][x] = 'X';

        // Get ship type at coordinate of opposing main board
        char ship_char = opposing_board->board_main[y][x];
        int ship_type_id;

        // Remove ship piece from opposing main board
        opposing_board->board_main[y][x] = 'X';

        // TODO: Maybe move this to ship class?
        // Convert ship character to type id
        switch (ship_char) {
            case 'C':
                printw("Carrier hit!\n");
                ship_type_id = 0;
                break;
            case 'B':
                printw("Battleship hit!\n");
                ship_type_id = 1;
                break;
            case 'D':
                printw("Destroyer hit!\n");
                ship_type_id = 2;
                break;
            case 'S':
                printw("Submarine hit!\n");
                ship_type_id = 3;
                break;
            case 'P':
                printw("Patrol Boat hit!\n");
                ship_type_id = 4;
                break;
            default:
                printw("Invalid ship hit!\n");
                ship_type_id = -1;
                break;
        }

        std::vector<std::pair<int, int> > coord_list = opposing_board->ship_list.at(ship_type_id).get_coordinates();
        std::pair<int, int> coord_to_delete = std::pair<int, int>(x, y);

        coord_list.erase(
            std::remove(coord_list.begin(), coord_list.end(), coord_to_delete)
        );
        
    }
    else // If missed attack
    {
        board_secondary[y][x] = 'F';
    }

    // Inform user of successful attack
    printw("Attack successful @ (%d, %d)\n", x, y);
    refresh();

    return 0;
}
