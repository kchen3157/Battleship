#ifndef __PLAYERIO_HH__
#define __PLAYERIO_HH__

#include "board.hh"
#include "ship.hh"
#include <array>


/** Gets a string input from the user via ncurses.
    @param: none
    @return: std::string
*/
std::string get_user_input_string();

/** Gets a user's starting board.
    @param: Board* board
    @param: int player_num
    @return: int
*/
int get_user_start_board(Board* board, int player_num);


/** Gets and executes an attack.
    @param: Board* atk_board
    @param: Board* opp_board
    @param: int atk_player_num
    @return: int
*/
int get_user_attack(Board* atk_board, Board* opp_board, int atk_player_num);

#endif  // __PLAYERIO_HH__
