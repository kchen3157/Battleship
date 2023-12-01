// include libraries
#include <array>
#include <string>
#include <vector>
#include "ship.hh"


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