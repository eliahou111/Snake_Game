#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>

class Screen {
private:
    int row, col; // dimensions of the game window
    void print_borders(); // draw the border around the edge of the window

public:
    Screen();
    bool kbhit(); // has a key on the keyboard been pressed by the user?
    void drawChar(int x, int y, char ch); // draw a character on the screen at (x,y)

    ~Screen();
};

#endif
