//file che si occupa del view e del board

#pragma once
#include "Drawable.hpp"
#include <cstdlib>
#include "ncurses.h"
//#include "window.h"
#include <time.h>
#include "Time.hpp"

extern const int BOARD_DIM = 17;
extern const int BOARD_ROWS = BOARD_DIM;
extern const int BOARD_COLS = BOARD_DIM * 2.5;

class Board
{
private:
	WINDOW *board_win; 																			// tutto questo e' per init del board
	int timeout;
	void construct(int height, int width, int speed);

public:
	Board();
	Board(int height, int width, int speed);
	void initialize();
	void addBorder();
	void add(Drawable drawable);

	void addAt(int y, int x, chtype ch);
	chtype getInput();

	void getEmptyCoordinates(int &y, int &x);

	chtype getCharAt(int y, int x);
	void clear();
	int getTimeout();

	void setTimeout(int timeout);
};