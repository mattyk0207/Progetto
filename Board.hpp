#pragma once

#include "ncurses.h"

#define BOARD_COLS 92
#define BOARD_ROWS 32

class Board 
{
private:
    WINDOW *board_win;
public:
    Board();
};