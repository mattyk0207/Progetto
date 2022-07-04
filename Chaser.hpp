// nemico che ti segue

#pragma once
#include "Characters.hpp"

class Chaser : public Characters
{
public:
    Chaser()
    {
        Characters();
        this->icon = 'C';
        this->x = 10;
        this->y = 10;
    }
    // override di characters
    void ChooseDirection(Board board_win, Characters &hero) override
    {
        int distancex, distancey;
        distancex = this->x - hero.x;
        distancey = this->y - hero.y;
        if (abs(distancex) < 10 || abs(distancey) < 10)
        {
            // se sei vicino
            if (abs(distancex) > abs(distancey))
            {
                if (distancex < 0)
                {
                    setDirection(dx);
                }
                else
                {
                    setDirection(sx);
                }
            }
            else
            {
                if (abs(distancex) <= abs(distancey))
                {
                    if (distancey < 0)
                    {
                        setDirection(down);
                    }
                    else
                    {
                        setDirection(up);
                    }
                }
            }
        }
    }
};