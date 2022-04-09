#include "Board.hpp"
#include <windows.h>


class Game {
private:
    bool game_over;
    Board game_board;
    Board score_board;
public:
    Game();

    bool isNotOver();    //verifica che il gioco non sia terminato

    void processInput();    //gestisce gli input da tastiera

    void updateState();     //aggiorna il punteggio e lo stato del gioco

    void updateScreen();    //aggiorna lo schermo

    friend void is_rigth_time();   //funzione per il clock
};
