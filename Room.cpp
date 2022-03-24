#include "Room.hpp"

//fa il set up della stanza scegliendo un template, istanziando i nemici e gli artefatti
//poi posiziona il giocatore 
//una versione senza parametri per la stanza di partenza e una con per le altre
Room::Room() {

    centerPlayer();

    initializeRoomTemplate(0);

    initializeEnemies();

    initializeArtifacts();

    linkRoom();

}

Room::Room(/*args*/) {

    centerPlayer();

    initializeEnemies();

    initializeArtifacts();

    linkRoom();

}

void Room::initializeRoomTemplate(int template_num) {

    switch (template_num) {
    case 0:
        cpyRoomGrid(template_0);
        break;
    
    default:
        break;
    }
}

void cpyRoomGrid(char room_template[]) {
    //doppio ciclo for per copiare la matrice
}

void centerPLayer() {
    coord middle;
    middle.x = 0;
    middle.y = 0;
    initializePlayer(middle);
}

