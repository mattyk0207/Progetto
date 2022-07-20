// file che si occupa del personaggio
#pragma once
#include "characters.hpp"
#include <ncurses.h>

class Hero : public Characters
{
public:
	Hero()
	{
		Characters();
		this->icon = 'P';
		this->x = 3;
		this->y = 3;
	}

	// input
	void takeDirection(Board game_board)
	{
		chtype input = game_board.getInput();
		int old_timeout = game_board.timeout;
		switch (input)
		{
		case KEY_UP:
		case 'w':
			setDirection(up);
			break;
		case KEY_DOWN:
		case 's':
			setDirection(down);
			break;
		case KEY_RIGHT:
		case 'd':
			setDirection(dx);
			break;
		case KEY_LEFT:
		case 'a':
			setDirection(sx);
			break;
		case 'p':
			game_board.setTimeout(-1);
			while (game_board.getInput() != 'p')
				;
			game_board.setTimeout(old_timeout);
		default:
			setDirection(def); // per non forzare movimento
			break;
		}
	}
};
