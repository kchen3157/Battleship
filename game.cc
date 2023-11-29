// Main Game loop

#include "board.hh"
#include "ship.hh"
#include "player_input.hh"
#include <array>
#include <curses.h>

int main()
{
    initscr(); // Initialize ncurses
    refresh(); // Refresh screen

    Board board_p0, board_p1;           // Player 0 and 1 boards
    
    // Retrieve starting board from players
    get_user_start_board(&board_p0, 0);
    get_user_start_board(&board_p1, 1);
    
    nocbreak();        

    // Main game loop
    while (true)
    {
        // Player 0 turn
        printw("Player 0: Your turn. Press enter to continue.\n");
        refresh();
        getch();
        clear();

        printw("*******************PLAYER 0********************\n\n\n");

        // Print Player 0 boards
        board_p0.print_main();
        board_p0.print_secondary();

        printw("Enter your move (xy): ");
        refresh();

        // Get user input
        std::string user_input;

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

        // Attack player 1 board
        board_p0.attack((int)(user_input[0] - '0'), (int)(user_input[1] - '0'), &board_p1);


        // Player 1 turn
        printw("Player 1: Your turn. Press enter to continue.\n");
        refresh();
        getch();
        clear();
        refresh();
    }

    endwin(); // End ncurses

    return 0;
}