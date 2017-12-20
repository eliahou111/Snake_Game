#include "worm.h"

#include <iostream>

// place worm on the board and give it an initial direction

Worm::Worm(char symbol) {

    head_symbol = symbol;
	body_symbol = 'o';
    head.X=50;
    head.Y=10;
    wormDirection = RIGHT;
	grow = 0;
	arraySize = bodySize = 1;
    body = new Position[bodySize];
	
	// give body positions next to head
	for (int i = 0; i < bodySize; i++) { 
		body[i].X = head.X - i - 1;
		body[i].Y = head.Y;
	} // end for

} // end constructor

/// map the current Direction to the appropriate change in (x,y) position
int Worm::move(Screen &screen) {
	
	screen.drawChar(head.X, head.Y, ' ');
    
	Position temp = head;

	switch(wormDirection) {
    case UP: head.Y--;
		break;
    case DOWN: head.Y++;
        break;
    case LEFT: head.X--;
        break;
    case RIGHT: head.X++;
        break;
    };
    
	// make pretty color for worm
	initscr(); 
	start_color();  
	init_color(COLOR_WHITE, 1000, 1000, 1000); // overwrite magenta
        init_pair(1, COLOR_GREEN, COLOR_BLACK); // overwrite color pair 1
	assume_default_colors(COLOR_WHITE, COLOR_BLACK);  // background color
	attron(COLOR_PAIR(1) | A_BOLD);

	screen.drawChar(head.X, head.Y, head_symbol);

	// if worm ate food and needs to grow, stop erasing last body piece
	if(grow)
		grow--;
	else	
		screen.drawChar(body[bodySize -1].X, body[bodySize -1].Y, ' ');

	// move all positions down one slot in array (to move the worm)
	for(int i = bodySize - 1; i >= 0; i--)  
		body[i] = body[i - 1];
	
	body[0] = temp;	 // first part of body takes value where head was
	
	screen.drawChar(body[0].X, body[0].Y, body_symbol);
	
	attroff(COLOR_PAIR(1) | A_BOLD);  // stop printing in color
	
	screen.drawChar(0,0,'*');

	return 1;
}

// map keyboard input to an internal direction

void Worm::setDirection(int direction_char) {
    
	wormPreviousDirection = wormDirection;
	
	switch(direction_char) {
    case 'a':
    case 'H':
    case 'h': wormDirection = LEFT;
        break;
    case 'd':
    case 'L':
    case 'l': wormDirection = RIGHT;
        break;
    case 's':
    case 'J':
    case 'j': wormDirection = DOWN;
        break;
    case 'w':
    case 'K':
    case 'k': wormDirection = UP;
        break;
    }
	
	// dont allow user to go backwards by accident
	if((wormPreviousDirection == UP && wormDirection == DOWN) || 
	   (wormPreviousDirection == DOWN && wormDirection == UP) || 
	   (wormPreviousDirection == LEFT && wormDirection == RIGHT) ||
	   (wormPreviousDirection == RIGHT && wormDirection == LEFT)) {

		wormDirection = wormPreviousDirection;
	} // end if 

} // end setDirection

/// overloading postfix operator to mean that more slots will be added to the
/// array, by dynamic memory allocation
void Worm::operator++(int) {
	Position *temp = new Position[arraySize * 2]; // new longer array
	std::copy(body, body + arraySize, temp);  // copy data to long array
	
	delete [] body; // delete shorter array
	body = temp;  
	
	arraySize *= 2; 
	
	temp = NULL;   // point temp pointer to NULL

} // end overloaded operator 
