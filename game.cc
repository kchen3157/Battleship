// Main Game loop

#include "board.hh"
#include "ship.hh"
#include "playerio.hh"

#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#endif

#include <array>
#include <curses.h>

int main()
{


    initscr();
    cbreak();

    Board board_p0, board_p1; // Player 0 and 1 boards

    int turn_result; // Temp integer to store result of turn

    // Retrieve starting board from players
    get_user_start_board(&board_p0, 0);
    get_user_start_board(&board_p1, 1);

    // char board[10][10] = {
    //     {'C', 'B', 'D', 'S', 'P', '_', '_', '_', '_', '_'},
    //     {'C', 'B', 'D', 'S', 'P', '_', '_', '_', '_', '_'},
    //     {'C', 'B', 'D', 'S', '_', '_', '_', '_', '_', '_'},
    //     {'C', 'B', '_', '_', '_', '_', '_', '_', '_', '_'},
    //     {'C', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
    //     {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
    //     {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
    //     {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
    //     {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
    //     {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
    // };

    // board_p0.set(board);
    // board_p1.set(board);

    // Main game loop
    while (true) {
        // Player 0 turn
        do
        {
            turn_result = get_user_attack(&board_p0, &board_p1, 0);

            if (turn_result == 1)
            {
                return 0;
            }
        }
        while (turn_result);

        // Player 1 turn
        do
        {
            turn_result = get_user_attack(&board_p1, &board_p0, 1);

            if (turn_result == 1)
            {
                return 0;
            }
        }
        while (turn_result);
    }

    endwin(); // End ncurses

    return 0;
}