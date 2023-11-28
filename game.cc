// Main Game loop

#include "board.hh"
#include "ship.hh"
#include "player_input.hh"
#include <array>

int main()
{
    Board board_p0, board_p1;           // Player 0 and 1 boards
    
    // Retrieve starting board from players
    get_user_start_board(&board_p0, 0);
    get_user_start_board(&board_p1, 1);


    return 0;
}