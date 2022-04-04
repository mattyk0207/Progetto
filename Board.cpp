#pragma once 

#include "Board.hpp"

Board::Board() 
{
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    board_win = newwin(BOARD_ROWS, BOARD_COLS, ((y_max/2)-(BOARD_ROWS/2)), ((x_max/2)-(BOARD_COLS/2)) );
    box(board_win, 0, 0);
    wrefresh(board_win);

}