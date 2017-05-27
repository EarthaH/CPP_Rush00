#ifndef SHIP_H
# define SHIP_H

#include <iostream>
#include <curses.h>
#include "Object.hpp"

class       Ship: public Object
{
    public:
        Ship();
        Ship(int, int, char);
        Ship(Ship const &);
        Ship operator=(Ship const &);
        ~Ship();
        void    shoot();
};

#endif