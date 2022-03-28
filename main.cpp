//file principale con il main che crea l'oggetto di gioco

#include <Game.hpp>
#include <ncurses.h>


int main() {
    initscr();
    cbreak();
    refresh();

    Game game;    //istanzaiamento oggetto che gestisce il gioco

    while(game.isNotOver()) {   //ciclo pricipale

        game.processInput();

        game.updateState();

        game.updateScreen();

    }


    getch();
    endwin();

    return 0;
}
