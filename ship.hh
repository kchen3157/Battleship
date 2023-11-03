#ifndef __SHIP_HH__
#define __SHIP_HH__

#include <array>
#include <string>

class Ship
{
    public:
        // Constructor
        Ship(int type_id, int owner);

        int get_type();

        int get_owner();

        std::string get_name();

        int get_length();
        
    private:
        int type_id;
        int length;
        int owner;
        std::string name;
};


#endif  // __SHIP_HH__
