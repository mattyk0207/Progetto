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
#include "Artifacts.hpp"
#include <vector>
#include "shooter.hpp"
#pragma once
extern const int GameSpeed=2;
using namespace std;
class Game
{
protected:
	bool game_over;
	Board game_board;
	Hero hero;
	Artifacts artifacts;
	// init di board e hero
	int herostartx = 15, herostarty = 15;
	int canMove = 0;
	// Board score_board;
	// da implementare
	vector<Enemy *> enemy;
public:
	Game(int height, int width, int speed)
	{

		game_board = Board(height, width, speed);
		hero.y = herostartx;
		hero.x = herostartx;
		// listanemici
		Coward *firstenemy = new Coward();
		enemy.push_back(firstenemy);
		Chaser *secondenemy = new Chaser();
		enemy.push_back(secondenemy);
		Shooter *thirdenemy = new Shooter();
		enemy.push_back(thirdenemy);
		artifacts = Artifacts();
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
		initializeArtifacts();
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
	void initializeArtifacts()
	{
		startdraw(artifacts);
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
			{ 
				enemy[i]->ChooseDirection(game_board, hero);
				game_board.remove(*enemy[i]);
				if (enemy[i]->checkCollision(game_board) && canMove<=1)
				{
					
					enemy[i]->moveCharacter();
				}
				enemy[i]->checkProjectile(game_board, hero);
				game_board.add(*enemy[i]);
				enemy[i]->setDirection(def);
			}
		}

		// % velocita'
		if(canMove>1){
		canMove--;
		}
		else{
		canMove=GameSpeed;
		}
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
