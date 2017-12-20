#include "fun.h"

#include <ncurses.h>
#include <iostream>

/// prints my personal signature
void printSignature () {
	clear();	// clear screen
	refresh();  // show on screen
	
	attron(COLOR_PAIR(1));	// turn on attribute color pair 1
	mvaddstr(5,0, "This game has been brought to you by:");
	
	init_pair(2, COLOR_BLUE, COLOR_BLACK);  // overwrite color pair 2
	attron(COLOR_PAIR(2));  
	mvaddstr(9,0, "Eliahou Mayor Corporations"); 
	
	init_pair(3, COLOR_RED, COLOR_BLACK); 
	attron(COLOR_PAIR(3)); 
	mvaddstr(13,0, "You are Welcome");
	
	attroff(COLOR_PAIR(3)); // turn off attributes
	
	refresh();  	
	// ensures message comes up even if a key is hit numerous times before
	// it is displayed (worm slams into a wall)
	for (int i = 0; i < 100; i++)
		getch();

	endwin();  // end curses mode

} // end printSignature
