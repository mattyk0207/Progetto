
#define ROOM_LENGTH 4
#define ROOM_WIDTH 91
#define DOORS_LENGTH 4

/*L'approccio con una matrice per rappresentare tutta la stanza dava problemi con la grafica e 
non era effiiente copiare tutta la matrice per ogni stanza
Quindi uso array a 2 dimensioni solo per muri e porte*/

class general_template {
public:
    int walls[4][2];
    int walls_num;
    int doors[][2];
    int doors_num;
};

class template_0 : public general_template {
public:
    int walls[4][2] = {{10,10},{23,11},{4,12},{25,30}};
    int walls_num = 4;
    int doors[][2] = {/*.....*/};
    int doors_num = 4*DOORS_LENGTH;
};
