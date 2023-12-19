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



/** Prints the game state.
    @param: Board* atk_board
    @param: int atk_player_num
    @return: none
*/
void print_game_state(Board* atk_board, int atk_player_num);


/** Prints instructions for getting a starting board.
    @param: Board* board
    @param: int player_num
    @param: int ship_ids_left
    @return: none
*/
void print_get_start_board_instructions(Board* board, int player_num, int ship_ids_left);


#endif  // __PLAYERIO_HH__
