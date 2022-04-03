#include "Room.hpp"

//fa il set up della stanza scegliendo un template, istanziando i nemici e gli artefatti
//poi posiziona il giocatore 
//una versione senza parametri per la stanza di partenza e una con per le altre
Room::Room() {

    initializeRoomTemplate(0);

    //centerPlayer();

    //initializeEnemies();

    //initializeArtifacts();

    //linkRoom();

}

Room::Room(int room_template) {

    initializeRoomTemplate(room_template);

    //centerPlayer();

    //initializeEnemies();

    //initializeArtifacts();

    //linkRoom();

}

void Room::initializeRoomTemplate(int template_num) {

    this->room_template_number = template_num;
    switch (this->room_template_number)
    {
    case 0:
        template_0 temp_0;
       //this->room_template = temp_0;
       multiarrcpy(room_template.walls, temp_0.walls);
       this->room_template.walls_num = temp_0.walls_num;
       break;
    }
}

void Room::drawRoom(WINDOW* win) {

    //drawPlayer();
    //drawEnemy();

    drawWalls(win);
    //drawDors();
}

void Room::drawWalls(WINDOW* win) {

    for(int i = 0; i < this->room_template.walls_num ; i++) {
        mvwprintw(win, room_template.walls[i][0], room_template.walls[i][1], "X");
    }
    wrefresh(win);
}


void Room::multiarrcpy(int cpy[][2], int orgn[][2]) {
    for(int i = 0; i < this->room_template.walls_num ; i++) { 
        cpy[i][0] = orgn[i][0];
        cpy[i][1] = orgn[i][1];
    }
}


void centerPLayer() {
    coord middle;
    middle.x = 0;
    middle.y = 0;
    //initializePlayer(middle);
}
