// file principale con il main che crea l'oggetto di gioco

#include "Game.hpp"
#include "Board.hpp"
using namespace std;
extern const int refreshspeed = 300;
int main()
{
	// da aggiungere scoreboard e un modo di fare gameover
	initscr();
	noecho();
	cbreak();
	refresh();
	curs_set(0);
	// funzioni init di ncurses
	Game game = Game(BOARD_ROWS, BOARD_COLS, refreshspeed);
	// inizializzazione
	while (game.isNotOver())
	{
		// ciclo pricipale

		game.processInput();
		// input

		game.updateState();
		// collisioni e movimento

		game.updateScreen();
		// refresh
	}
	cout << "game over";
	getch();
	endwin();

	return 0;
}
/*ci potrebbero e ci sono alcune cose ridondanti ma scio'
la funzione per il tempo potrebbe non funzionare su tutte le macchine
cambiate il nome delle variabili se volete ma fatelo bene
prob aggiungo un nemico che spara o il drunk diventa 2x2
non credo che aggiungo direzione diagonale
io ho finito la mia parte arrangiatevi
bacetti<3<3
*/
