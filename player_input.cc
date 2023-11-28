#include "board.hh"
#include "ship.hh"

#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#endif

#include <array>
#include <ncurses.h>

int get_user_start_board(Board* board, int player_num)
{
    int ship_ids_left = 0b00011111;     // Binary representation of five ship types

    while (ship_ids_left) // While there are still ships left to place
    {
        std::string user_input;             // Temp string to assist user input

        // Print user instructions
        printw("*******************PLAYER %i********************\n", player_num);
        printw("Enter ship type, then x, y, then direction (r, l, u, d)\n\n");
        attron(A_BOLD);
        printw("Ships left:\nType\t\tID\tLength\n");
        attroff(A_BOLD);


        // Print list of ships left to place
        for (int i = 0; i < NUM_SHIP_TYPES; i++)
        {
            // If ship still left, print
            if (ship_ids_left & (0b00000001 << i))  
            {
                printw("%-15s\t%i\t%i\n", SHIP_NAMES[i].c_str(), i, SHIP_LENGTHS[i]);
            }
            else
            {
                printw("\n");
            }
        }

        // Padding
        printw("\n\n");

        // Print board
        board->print();

        // Obtain user input
        printw("Enter your move: ");
        refresh();
        nocbreak();
        echo();
        int ch = getch();
        while (ch != '\n')
        {
            user_input.push_back( ch );
            ch = getch();
        }
        noecho();

        // Parse user input
        int x = (int) (user_input[1] - '0');            // x coord of ship
        int y = (int) (user_input[2] - '0');            // y coord of ship
        char direction = user_input[3];                 // direction of ship
        int type_id = (int) (user_input[0] - '0');      // type of ship
        int type_id_binary = 0b00000001 << type_id;     // type of ship in binary


        if (ship_ids_left & type_id_binary) // If ship left
        {
            //Place ship
            board->place_ship(x, y, direction, Ship(type_id, 0));
            
            // Remove ship from list of ships left
            ship_ids_left &= ~type_id_binary;
        }
        else
        {
            printw("Ship already placed!\n");
        }

        refresh();
        sleep(1);

        clear();
        refresh();
    }

    board->print();
    printw("\n\nPlayer %i: All ships placed!\n", player_num);
    refresh();
    sleep(2);
    clear();
    refresh();

    return 0;
}
