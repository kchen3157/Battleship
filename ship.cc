// Defines ship variables


// include libraries
#include <array>
#include <string>

// Env Vars
const int SHIP_TYPE_NUMBER = 5;
std::array<std::string, SHIP_TYPE_NUMBER> SHIP_TYPES = 
    {
    "Carrier",      // 0
    "Battleship",   // 1
    "Cruiser",      // 2
    "Submarine",    // 3
    "Destroyer"     // 4
    };   




class Ship
{
    public:
        // Constructor
        Ship(int type_id);

        /** Gets the type of ship
            @param: none
            @return: int
        */
        int get_type();

        /** Get owner of ship
            @param: none
            @return: int
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
        int owner;
        std::string name;
};


Ship::Ship(int type_id)
{
    this->type_id = type_id;
}