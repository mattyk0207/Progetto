// file controller di funzioni e del gioco
#include <iostream>
//#include <windows.h>
// vedete voi se metterlo da me da errori e non mi serve
#include <time.h>
#include <stdlib.h>
#include "Hero.hpp"
#include "drunkenemy.hpp"
#include "chaser.hpp"
#include "coward.hpp"
#include <vector>
#pragma once
using namespace std;
class Game
{
protected:
	bool game_over;
	Board game_board;
	Hero hero;
	// init di board e hero
	int herostartx = 15, herostarty = 15;
	bool canMove = true;
	// Board score_board;
	// da implementare
	vector<Characters *> enemy;

public:
	Game(int height, int width, int speed)
	{

		game_board = Board(height, width, speed);
		hero.y = herostartx;
		hero.x = herostartx;
		// listanemici
		Coward *firstenemy = new Coward();
		enemy.push_back(firstenemy);
		Chaser *secondenemy = new Chaser;
		enemy.push_back(secondenemy);
		Drunk *thirdenemy = new Drunk();
		enemy.push_back(thirdenemy);

		initialize();
	}
	// inizialize
	void initialize()
	{
		game_board.initialize();
		game_over = false;
		game_board.add(hero);
		hero.setDirection(def);
		initializeEnemies();
	}
	void initializeEnemies()
	{
		int i;
		for (i = 0; i < enemy.size(); i++)
		{
			if (enemy[i] != nullptr)
			{
				startdraw(*enemy[i]);
				enemy[i]->setDirection(def);
			}
		}
	}
	// draw initialize
	void startdraw(Drawable &drawable)
	{
		game_board.getEmptyCoordinates(drawable);
		game_board.addAt(drawable.y, drawable.x, drawable.icon);
	}
	bool isNotOver()
	{
		return !game_over;
	}
	// input
	void processInput()
	{ // input e direction
		hero.takeDirection(game_board);
		// per non duplicare
	}

	// movimenti
	void updateState()
	{
		// hero
		game_board.remove(hero);
		if (hero.checkCollision(game_board))
		{
			hero.moveCharacter();
		}
		hero.setDirection(def);
		game_board.add(hero);
		// enemies
		int i;
		for (i = 0; i < enemy.size(); i++)
		{
			if (enemy[i] != NULL)
			{ // chiama solo collision
				enemy[i]->ChooseDirection(game_board, hero);
				game_board.remove(*enemy[i]);
				if (enemy[i]->checkCollision(game_board) && canMove)
				{
					enemy[i]->moveCharacter();
				}

				game_board.add(*enemy[i]);
				enemy[i]->setDirection(def);
			}
		}
		// 50% velocita'
		canMove = !canMove;
	}

	// refresh
	void updateScreen()
	{ // riaggiunge e refresh
		refresh();
	}

	void redraw() // riaggiunge
	{
		game_board.add(hero);
		int i;
		for (i = 0; i < enemy.size(); i++)
		{
			if (enemy[i] != NULL)
			{
				game_board.add(*enemy[i]);
			}
		}
	}
};
