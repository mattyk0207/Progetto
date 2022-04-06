#include <ncurses.h>

int main() {
    
    initscr();
    refresh();

    printw("Hello World");
    refresh();
    
    getch();
    endwin();
    return 0;
}