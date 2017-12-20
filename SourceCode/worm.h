#ifndef WORM_H
#define WORM_H

#include "screen.h"
#include "position.h"

class Worm {
private:

    // easy way to represent related values
    enum Direction {
        UP,
        DOWN,
	    LEFT,
        RIGHT,
    };

    char head_symbol; // character to represent worm's head
    char body_symbol;  // character for worm's body
	Position head;   // position of worm's head
	Position *body; // array of positions for worm's body
	int bodySize; // size of the worm's body
	int arraySize; // size of the array
	int grow;  // how much worm needs to grow by
    Direction wormDirection; // direction worm is traveling
	Direction wormPreviousDirection;  // direction worm was traveling last move

public:
    Worm(char symbol='@');
    int move(Screen &screen);
    void setDirection(int direction_char);
	Position getHeadPosition() {return head; }
	Position* getBodyPosition() {return body; }
	int getBodySize() {return bodySize; }
	void setBodySize(int size) { bodySize += size;} 
	int getArraySize() {return arraySize; }
	void setGrow(int value) { grow += value; }
	void operator++(int);
};

#endif
