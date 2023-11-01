// Defines ship variables


// include libraries
#include <array>
#include <string>

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
        
    private:
        int type_id;
        int length;
        int owner; // 0 for player, 1 for computer
        char char_code;
        std::string name;
};


Ship::Ship(int type_id, int owner)
{
    this->type_id = type_id;
    this->owner = owner;
    this->char_code = SHIP_CHAR_CODES[type_id];
    this->name = SHIP_NAMES[type_id];
    this->length = SHIP_LENGTHS[type_id];
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
    return this->name;
}

int Ship::get_length()
{
    return this->length;
}