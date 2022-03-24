#include "RoomTemplates.hpp"


struct coord
{
    int x;
    int y;
};


class Room {
private:
    coord room_coordinates;
    bool has_left_door;
    bool has_right_door;
    bool has_top_door;
    bool has_bottom_door;
    char room_grid[ROOM_LENGTH][ROOM_WIDTH];
public:
    Room();
    
    void initializeRoomTemplate(int template_num);

    void linkRoom();

    void drawRoom();

    friend void cpyRoomGrid(char room_template[]);  // ??? forse doppia quadra [][]
};

void centerPlayer();

void initializeEnemies();

void initializeArtifacts();

void initializePlayer(coord player_coordinates);