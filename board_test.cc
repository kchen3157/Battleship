// Application to test the board placing ship functions.

#include "board.hh"
#include "ship.hh"


int main()
{
    Board board;

    // Place ship unsuccessfully
    std::cout << "Testing off-board place_ship() @ (0,0) LEFT\n";
    board.place_ship(0, 0, 'l', Ship(0, 0));
    board.print();
    board.erase(); // Erase board
    std::cout << "\n\n\n";

    // Place ship successfully
    std::cout << "Testing valid place_ship() @ (0,0) RIGHT\n";
    board.place_ship(0, 0, 'r', Ship(0, 0));
    board.print();

    // Place ship unsuccessfully
    std::cout << "Testing occupied place_ship() @ (2,4) UP\n";
    board.place_ship(2, 4, 'u', Ship(0, 0));
    board.print();

    // Place ships successfully
    std::cout << "Testing occupied place_ship() @ (2,4) UP\n";
    board.place_ship(2, 4, 'u', Ship(1, 0));
    board.print();
    board.place_ship(7, 4, 'u', Ship(2, 0));
    board.print();
    board.place_ship(2, 8, 'r', Ship(3, 0));
    board.print();
    board.place_ship(7, 6, 'r', Ship(4, 0));
    board.print();


    // User test
    board.erase();
    std::cout << "Testing with user input\n";
    std::string user_input;

    for (;;)
    {
        // Print user instructions
        std::cout << "Enter ship type, then x, y, then direction (r, l, u, d)\n\n";
        std::cout << "Ship types:\n"
                    "Type\t\tID\tLength\n"
                    "Carrier\t\t0\t5\n"
                    "Battleship\t1\t4\n"
                    "Destroyer\t2\t3\n"
                    "Submarine\t3\t3\n"
                    "Patrol Boat\t4\t2\n\n";
        // Obtain user input
        std::cout << "Enter your move: ";
        std::cin >> user_input;


        int x = (int) (user_input[1] - '0');        // x coord of ship
        int y = (int) (user_input[2] - '0');        // y coord of ship
        char direction = user_input[3];             // direction of ship
        int type_id = (int) (user_input[0] - '0');  // type of ship

        board.place_ship(x, y, direction, Ship(type_id, 0));

        board.print();

    }




    return 0;
}