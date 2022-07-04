#pragma once 

//#include "RoomTemplates.hpp"
#include <ncurses.h>


class Room {
private:
    //int room_template_number;
    //general_template room_template;
public:
    int y; int x;
    Room* north; Room* south; Room* west; Room* est;

    Room();    //costrutture stanza di partenza

    Room(int y, int x, Room** room_index, int index_dim);   //costruttore stanza qualsiasi

    void drawRoom(WINDOW* win);

private:
    Room* findRoom(Room** room_index, int index_dim, int x, int y);
}; typedef Room* prm;

/*
//struttura che memorizza in un array le stanze per aggiornare i collegamenti e le porte
class RoomIndex {
private:
    prm* room_index;
    int index_dim;
    int current_index;
public:
    RoomIndex();

    ~RoomIndex();
    
    void addRoomToIndex(prm room);

    Room* findRoom(int y, int x);

    void updateIndex(prm room);
};
*/