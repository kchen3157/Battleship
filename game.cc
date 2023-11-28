// Main Game loop

#include "board.hh"
#include "ship.hh"
#include <array>

int main()
{
    Board board_p0, board_p1;           // Player 0 and 1 boards
    std::string user_input;             // Temp string to assist user input
    int ship_ids_left = 0b00011111;     // Binary representation of five ship types

    while (ship_ids_left != 0b00000000) // While there are still ships left to place
    {

        // Print user instructions
        std::cout << "Enter ship type, then x, y, then direction (r, l, u, d)\n\n";
        std::cout << "Ships left:\nType\t\tID\tLength\n";

        // Print list of ships left to place
        for (int i = 0; i < NUM_SHIP_TYPES; i++)
        {
            // If ship still left, print
            if (ship_ids_left & (0b00000001 << i))  
            {
                std::cout << SHIP_NAMES[i] << "\r\t\t" << i << "\t" << SHIP_LENGTHS[i] << "\n";
            }
        }

        // Print board
        board_p0.print();

        // Obtain user input
        std::cout << "Enter your move: ";
        std::cin >> user_input;

        // Parse user input
        int x = (int) (user_input[1] - '0');            // x coord of ship
        int y = (int) (user_input[2] - '0');            // y coord of ship
        char direction = user_input[3];                 // direction of ship
        int type_id = (int) (user_input[0] - '0');      // type of ship
        int type_id_binary = 0b00000001 << type_id;     // type of ship in binary

        if (ship_ids_left & type_id_binary) // If ship left
        {
            //Place ship
            board_p0.place_ship(x, y, direction, Ship(type_id, 0));
            
            // Remove ship from list of ships left
            ship_ids_left &= ~type_id_binary;
        }
        else
        {
            std::cout << "Ship already placed!\n";
        }
    }

    std::cout << "All ships placed!\n";

    return 0;
}