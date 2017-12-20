#include "screen.h"

Screen::Screen() {
    initscr(); // start ncurses mode
    getmaxyx(stdscr,row,col);  // get dimensions
    curs_set(0);  // make cursor invisible
    cbreak();     // get unbuffered characters
    noecho();     // typing doesn't show on screen
    nodelay(stdscr, true); // nonblocking input

    print_borders();
}

// put a character on the screen at horizontal position x and vertical position y

void Screen::drawChar(int x, int y, char ch) {
    mvaddch(y,x,ch);
}

void Screen::print_borders() {
    for (int i=0; i < row; i++) {
        mvaddch(i,0,'*');
        mvaddch(i,col-1,'*');
    }
    for (int i=0; i < col; i++) {
        mvaddch(0,i,'*');
        mvaddch(row-1,i,'*');
    }
}

// return true if a character has been typed (but don't actually read the character)

bool Screen::kbhit() {
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return true;
    } else {
        return false;
    }
}

// clean up screen and return

Screen::~Screen() {

    refresh();
    nodelay(stdscr,false);
    getch();
    endwin();
}
