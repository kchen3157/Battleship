#ifndef __SHIP_HH__
#define __SHIP_HH__

#include <array>
#include <string>
#include <vector>


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
        int type_id;                                // Ship ID (0-4)
        // int length;                              // Ship length
        int owner;                                  // 0 for player, 1 for computer
        // char char_code;                          // Representation of ship on board
        // std::string name;                        // Ship name
        std::vector<int> coordinates_occupied;      // Ship's occupied coordinates on board
};


#endif  // __SHIP_HH__
