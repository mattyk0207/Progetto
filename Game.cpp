#include "Game.hpp"

Game::Game(int height, int width, int speed)
{
	game_board = Board(height, width, speed);
	hero = Hero(herostarty, herostartx);
	initialize();
}

void Game::initialize()
{
	game_board.initialize();
	game_over = false;
	hero.addHero(herostarty, herostartx, game_board);
	hero.setDirection(def);
}

bool Game::isNotOver()
{
	return !game_over;
}

void Game::processInput()
{ 																								// input e direction
	chtype input = game_board.getInput();
	int old_timeout = game_board.getTimeout();
	switch (input)
	{
	case KEY_UP:
	case 'w':
		hero.setDirection(up);
		break;
	case KEY_DOWN:
	case 's':
		hero.setDirection(down);
		break;
	case KEY_RIGHT:
	case 'd':
		hero.setDirection(dx);
		break;
	case KEY_LEFT:
	case 'a':
		hero.setDirection(sx);
		break;
	case 'p':
		game_board.setTimeout(-1);
		while (game_board.getInput() != 'p');               //????????????????????
		game_board.setTimeout(old_timeout);
	default:
		hero.setDirection(def); 																// per non forzare movimento
		break;
	}
	hero.removeHero(game_board); 																// per non duplicare
}

void Game::checkCollision()
{ 																								// collisione
	int offsety = 0, offsetx = 0;
	if (hero.cur_direction == up || hero.cur_direction == down)
	{ 																							// offset per row e col per collisione
		offsety = hero.cur_direction / 2;
	}
	else
	{
		if (hero.cur_direction == dx || hero.cur_direction == sx)
		{
			offsetx = hero.cur_direction;
		}
	}
	switch (game_board.getCharAt(hero.gety() + offsety, hero.getx() + offsetx))
	{
		case ' ':
		hero.moveHero(); 																		// se si puo' muovere si muove
		hero.setDirection(def);
	    default:
		break;
	}
}

void Game::updateState()
{ 																								// chiama solo collision
	checkCollision();
}

void Game::redraw()																					// riaggiunge
{ 																							
	game_board.add(hero);
}

void Game::updateScreen()
{ 																								// riaggiunge e refresh
	redraw();
	refresh();
}