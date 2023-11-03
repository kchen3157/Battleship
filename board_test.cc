#include "board.hh"
#include "ship.hh"


int main()
{
    Board board;
    board.print_board();

    board.place_ship(1, 1, 'l', Ship(0, 0));
    board.print_board();

    return 0;
}