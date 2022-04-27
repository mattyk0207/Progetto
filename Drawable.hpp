// file che si occupa dei drawables
// base disegnabile senza direzione
#pragma once
#include <ncurses.h>
class Drawable
{
public:
	int y;
	int x;
	chtype icon;

	Drawable() // parent di hero
	{
		this->y = 0;
		this->x = 0;
		this->icon = ' ';
	}
};
