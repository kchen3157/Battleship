#ifndef __SHIP_HH__
#define __SHIP_HH__

#include <array>
#include <string>
#include <vector>

const int NUM_SHIP_TYPES = 5;
const std::array<std::string, NUM_SHIP_TYPES> SHIP_NAMES = 
    {
    "Carrier",      // 0
    "Battleship",   // 1
    "Destroyer",    // 2
    "Submarine",    // 3
    "Patrol Boat"   // 4
    };
const std::array<int, NUM_SHIP_TYPES> SHIP_LENGTHS = 
    {
    5,      // 0, Carrier
    4,      // 1, Battleship
    3,      // 2, Destroyer
    3,      // 3, Submarine
    2       // 4, Patrol Boat
    };  
const std::array<char, NUM_SHIP_TYPES> SHIP_CHAR_CODES = 
    {
    'C',      // 0, Carrier
    'B',      // 1, Battleship
    'D',      // 2, Destroyer
    'S',      // 3, Submarine
    'P'       // 4, Patrol Boat
    }; 

class Ship
{
    public:
        // Constructor
        Ship(int type_id, int owner);

        /** Gets the type of ship
            @param: none
            @return: int
        */
        int get_type();

        /** Get owner of ship
            @param: none
            @return: 0 for player, 1 for computer
        */
        int get_owner();

        /** Gets the name of ship
            @param: none
            @return: string
        */
        std::string get_name();

        /** Gets the length of ship
            @param: none
            @return: int
        */
        int get_length();

        /** Gets the char code of ship
            @param: none
            @return: char
        */
        char get_char_code();

        /** Adds a coordinate to the ship
            @param: int x, int y
            @return: none
        */
        void add_coordinate(std::pair<int, int> coordinate);

        /** Gets the coordinates of ship
            @param: none
            @return: std::vector<int>
        */
        std::vector<std::pair<int, int> > get_coordinates();
        
    private:
        int type_id;                                                 // Ship ID (0-4)
        // int length;                                               // Ship length
        int owner;                                                   // 0 for player, 1 for computer
        // char char_code;                                           // Representation of ship on board
        // std::string name;                                         // Ship name
        std::vector<std::pair<int, int> > coordinates_occupied;      // Ship's occupied coordinates on board
};


#endif  // __SHIP_HH__
