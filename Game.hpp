// file controller di funzioni e del gioco

#pragma once
#include "Board.hpp"
#include <iostream>
//#include <windows.h>
//vedete voi se metterlo da me da errori e non mi serve
#include <time.h>
#include <stdlib.h>
#include "Hero.hpp"


class Game
{
private:
	bool game_over;
	Board game_board; 																				// init di board e hero
	Hero hero;
	int herostartx = 3, herostarty = 3;
	// Board score_board;
	//da implementare

public:
	Game(int height, int width, int speed);

	void initialize();

	bool isNotOver();

	void processInput();

	void checkCollision();

	void updateState();

	void redraw();

	void updateScreen();
};