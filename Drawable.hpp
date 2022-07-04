//file che si occupa dei drawables
#pragma once
#include <ncurses.h>

class Drawable
{
public:
	Drawable();
	Drawable(int y, int x, chtype ch);
	int gety();
	int getx();
	chtype getIcon();

protected:
	int y, x;
	chtype icon;
};