#include "Ship.hpp"
#include <iostream>
#include <curses.h>

Ship::Ship()
{

}

Ship::Ship(Ship const & f)
{
    *this = f;
}

Ship::~Ship()
{
    
}

Ship  Ship::operator=(Ship const & f)
{
    this->_char = f._char;
    return (*this);
}

void    Ship::shoot()
{
    Object bullet(this->_row, this->_col, '-');
}