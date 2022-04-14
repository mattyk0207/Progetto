#pragma once

#include "ncurses.h"

#define BOARD_COLS 92
#define BOARD_ROWS 32

class Board 
{
public:
    WINDOW *game_win;
    Board();
};