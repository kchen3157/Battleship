#ifndef __PLAYERIO_HH__
#define __PLAYERIO_HH__

#include "board.hh"
#include "ship.hh"
#include <array>

std::string get_user_input_string();

int get_user_start_board(Board* board, int player_num);

int get_user_attack(Board* atk_board, Board* opp_board, int atk_player_num);

#endif  // __PLAYERIO_HH__
