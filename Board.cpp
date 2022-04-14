#pragma once 

#include "Board.hpp"

Board::Board() 
{
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    game_win = newwin(BOARD_ROWS, BOARD_COLS, ((y_max/2)-(BOARD_ROWS/2)), ((x_max/2)-(BOARD_COLS/2)) );
    box(game_win, 0, 0);
    wrefresh(game_win);

}