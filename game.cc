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
        refresh();


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