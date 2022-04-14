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

    Room(int y, int x, RoomIndex room_index);

    void drawRoom(WINDOW* win);

private:

}; typedef Room* prm;


class RoomIndex {
private:
    prm* room_index;
    int index_dim;
    int current_index;
public:
    RoomIndex();

    ~RoomINdex();
    
    void addRoomToIndex(prm room);

    Room* findRoom(int y, int x);

    void updateIndex(prm room);
};