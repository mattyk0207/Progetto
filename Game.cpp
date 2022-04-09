#include "Game.hpp"

Game::Game() {
    //creazione e inizializzazione della finestra di gioco 
    //creazione e inizializzazione della finestra del punteggio

    //funzione che crea stanza iniziale
    //inizializzazione PG
    //inizializzazione nemico (facile)

    //inizializzazone del clock
}

bool Game::isNotOver() {
    return game_over;
}

void Game::processInput() {
    //prende dallo schermo i comandi
    if(is_right_time) {

    }
}

bool is_right_time() {
    bool f = false;
    if(GetTickCount() % 1 == 0) f =  true;
    Sleep(1);   //necessario per non eseguire le operazioni di fila può essere migliorato
    return f;
}