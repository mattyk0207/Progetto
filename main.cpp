// file principale con il main che crea l'oggetto di gioco

#include "Game.hpp"
#include "Board.hpp"
#include <ncurses.h>
#include "Drawable.hpp"
#include <iostream>
using namespace std;
extern const int refreshspeed = 300;

int main()
{																				 // da aggiungere scoreboard e un modo di fare gameover
	initscr();
	noecho();
	cbreak();																	 // funzioni di inizializzazione di ncurses
	refresh();
	curs_set(0);

	Game game = Game(BOARD_ROWS, BOARD_COLS, refreshspeed); 					 // inizializzazione oggetto di gioco

	while (game.isNotOver())
	{ 																			 // ciclo pricipale
		game.processInput();													 // input , direzione e rimozione di hero

		game.updateState(); 													 // collisioni e movimento

		game.updateScreen();													 // refresh e add di hero
	}
	cout << "game over";
	getch();
	endwin();

	return 0;
}