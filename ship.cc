// include libraries
#include <array>
#include <string>
#include <vector>

// Env Vars
const int SHIP_TYPE_NUMBER = 5;
std::array<std::string, SHIP_TYPE_NUMBER> SHIP_NAMES = 
    {
    "Carrier",      // 0
    "Battleship",   // 1
    "Destroyer",    // 2
    "Submarine",    // 3
    "Patrol Boat"   // 4
    };
std::array<int, SHIP_TYPE_NUMBER> SHIP_LENGTHS = 
    {
    5,      // 0, Carrier
    4,      // 1, Battleship
    3,      // 2, Destroyer
    3,      // 3, Submarine
    2       // 4, Patrol Boat
    };  
std::array<char, SHIP_TYPE_NUMBER> SHIP_CHAR_CODES = 
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
            @param: std::pair<int, int>
            @return: none
        */
        void add_coordinate(std::pair<int, int> coordinate);

        /** Gets the coordinates of ship
            @param: none
            @return: std::vector<std::pair<int, int> >
        */
        std::vector<std::pair<int, int> > get_coordinates();
        
    private:
        int type_id;                                // Ship ID (0-4)
        // int length;                              // Ship length
        int owner;                                  // 0 for player, 1 for computer
        // char char_code;                          // Representation of ship on board
        // std::string name;                        // Ship name
        std::vector<std::pair<int, int> > coordinates_occupied;      // Ship's occupied coordinates on board
};


Ship::Ship(int type_id, int owner)
{
    // Fill in ship type
    if (type_id < 0 || type_id > 4) {
        throw std::invalid_argument("Ship Class: Invalid type_id");
    }
    this->type_id = type_id;

    // Fill in ship owner
    if (owner < 0 || owner > 1) {
        throw std::invalid_argument("Ship Class: Invalid owner");
    }
    this->owner = owner;

    // this->char_code = SHIP_CHAR_CODES[type_id];
    // this->name = SHIP_NAMES[type_id];
    // this->length = SHIP_LENGTHS[type_id];
}

int Ship::get_type()
{
    return this->type_id;
}

int Ship::get_owner()
{
    return this->owner;
}

std::string Ship::get_name()
{
    return SHIP_NAMES[this->type_id];
}

int Ship::get_length()
{
    return SHIP_LENGTHS[this->type_id];
}

char Ship::get_char_code()
{
    return SHIP_CHAR_CODES[this->type_id];
}

void Ship::add_coordinate(std::pair<int, int> coordinate)
{
    this->coordinates_occupied.push_back(coordinate);
}

std::vector<std::pair<int, int> > Ship::get_coordinates()
{
    return coordinates_occupied;
}