#pragma once

#include "Room.hpp"
#include "Board.hpp"
//#include "RoomIndex.hpp"


class Game 
{
private:
    bool game_over;
    Board gameboard;
    Room* current_room;
    Room** room_index;
    int index_dim;
    int current_index;
public:
    Game();

    ~Game();

    bool isNotOver();    //verifica che il gioco non sia terminato

    void processInput();    //gestisce gli input da tastiera

    void updateState();     //aggiorna il punteggio e lo stato del gioco

    void updateScreen();    //aggiorna lo schermo

    void checkCollisions();

private:
    void moveToNorthRoom();
    void moveToSouthRoom();
    void moveToWestRoom();
    void moveToEstRoom();

    void makeNorthRoom();
    void makeSouthRoom();
    void makeWestRoom();
    void makeEstRoom();

    void addRoomToIndex(prm room);
    void updateIndex(prm room);
};