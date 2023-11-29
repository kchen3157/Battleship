// Main Game loop

#include "board.hh"
#include "ship.hh"
#include "playerio.hh"
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
        get_user_attack(&board_p0, &board_p1, 0);

        // Player 1 turn
        get_user_attack(&board_p1, &board_p0, 1);

    }

    endwin(); // End ncurses

    return 0;
}