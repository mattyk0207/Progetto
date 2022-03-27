#include "RoomTemplates.hpp"
#include <ncurses.h>

struct coord {
    int x;
    int y;
};


class Room {
private:
    coord room_coordinates;
    int room_template_number;
    general_template room_template;
public:
    Room();

    void drawRoom(WINDOW* win);
private:

    void drawWalls(WINDOW* win);

    void  multiarrcpy(int cpy[][2], int orgn[][2]);

    void initializeRoomTemplate(int template_num);

    void linkRoom();
};

void centerPlayer();

void initializeEnemies();

void initializeArtifacts();

void initializePlayer(coord player_coordinates);

