//file che si occupa del personaggio

#pragma once
#include <ncurses.h>
#include "Drawable.hpp"
#include "Board.hpp"

enum Direction
{ 																							// direzioni
	up = -2,
	down = 2,
	sx = -1,
	dx = 1,
	def = 0
};

class Hero : public Drawable
{
public:
	Direction cur_direction;

	Hero();

	Hero(int y, int x);

	Direction getDirection();

	void setDirection(Direction newdir);

	void moveHero();

	int getx();
	int gety();
	int getIcon();
	void addHero(int y, int x, Board game_board);
	void removeHero(Board game_board);
};