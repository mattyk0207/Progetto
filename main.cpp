#include "ncurses.h"


int main() {
    initscr();
    cbreak();
    noecho();
    refresh();

    WINDOW* win = newwin(5, 50, 10, 100);
    box(win, 0, 0);
    wrefresh(win);


    getch();
    endwin();
    return 0;
}