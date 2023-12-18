#include "board.hh"
#include "ship.hh"

#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#endif

#include <array>
#include <ncurses.h>

std::string get_user_input_string()
{
    std::string user_input;
    refresh();
    noraw();
    echo();
    int ch = getch();
    while (ch != '\n')
    {
        user_input.push_back( ch );
        ch = getch();
    }
    noecho();
    raw();

    return user_input;
}

int get_user_start_board(Board* board, int player_num)
{
    // Integer to track the ships left to place
    int ship_ids_left = 0b11111;     // Binary representation of five ship types

    // Ensure player_num is 0 or 1
    if (player_num < 0 || player_num > 1)
    {
        throw std::invalid_argument("Playerio: get_user_start_board(), invalid player_num");
    }
    

    while (ship_ids_left) // While there are still ships left to place
    {

        // Print user instructions
        printw("*******************PLAYER %i********************\n", player_num);
        printw("Enter ship type, then x, y, then direction (r, l, u, d)\n\n");


        // Print list of ships left to place
        attron(A_BOLD); // Bold typeface
        printw("Ships left:\nType\t\tID\tLength\n");
        attroff(A_BOLD);
        for (int i = 0; i < NUM_SHIP_TYPES; i++)
        {
            // If ship still left, print it out
            if (ship_ids_left & (1 << i))  
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
        board->print_main();


        // Obtain user input
        printw("Enter your move: ");
        refresh();
        std::string user_input = get_user_input_string();

        // Parse user input
        int x = user_input[1] - '0';            // x coord of ship
        int y = user_input[2] - '0';            // y coord of ship
        char direction = user_input[3];         // direction of ship
        int type_id = user_input[0] - '0';      // type of ship
        int type_id_binary = 1 << type_id;      // type of ship in binary


        if (ship_ids_left & type_id_binary) // If ship left
        {
            //Place ship
            while(board->place_ship(x, y, direction, Ship(type_id, 0)));

            // Remove ship from list of ships left
            ship_ids_left &= ~type_id_binary;
        }
        else
        {
            printw("Ship already placed or invalid ship!\n");
        }

        // Display feedback for one second before continuing
        refresh();
        sleep(1);
        clear();
        refresh();
    }

    // When all ships placed, inform user and continue after two seconds.
    board->print_main();
    printw("\n\nPlayer %i: All ships placed!\n", player_num);
    refresh();
    sleep(2);
    clear();
    refresh();

    return 0;
}

int get_user_attack(Board* atk_board, Board* opp_board, int atk_player_num)
{
    // Continuation screen to hide board
    clear();
    printw("Player %i: Your turn. Press enter to continue.\n", atk_player_num);
    refresh();
    getch();
    clear();

    // Print player header
    printw("*******************PLAYER %i********************\n\n\n", atk_player_num);

    // Print attacking boards
    atk_board->print_main();
    atk_board->print_secondary();

    // Print instructions
    printw("Enter your move (xy): ");
    refresh();

    // Get user input
    std::string user_input = get_user_input_string();

    // Attack opposing board
    return atk_board->attack((int)(user_input[0] - '0'), (int)(user_input[1] - '0'), opp_board);
}

