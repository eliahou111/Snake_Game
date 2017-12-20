#include "player.h"

#include <sstream>   // to convert int to string
#include <ncurses.h>  // for bolding and colors
#include <unistd.h>  // for sleep()

/// checks if the game is over by checking if the head hit the wall
void Player::isGameOver(Worm &worm, bool &gameOver) {
	Position head = worm.getHeadPosition();
	Position *body = worm.getBodyPosition();
	int size = worm.getBodySize();
	
	// if worm hits a wall
	if (head.X == 0 || head.X == 79 ||
		head.Y == 0 || head.Y == 23) 

		gameOver = true;
	
	// if worm hits itself
	for(int i = 3; i < size; i++)
		if(body[i] == head)
			gameOver = true;

} // end isOver

/// if food was eaten, grow the array accordingly
void Player::growWorm(Food &food, Worm &worm) {
	int capacity = worm.getArraySize() - worm.getBodySize();					
	
	// while no space to grow body as per value eaten
	while(capacity < food.getFoodValue() &&
	      food.isEaten(worm.getHeadPosition())) {
		
		worm++; // increase dynamic memory
		capacity = worm.getArraySize() - worm.getBodySize();
		} // end while 	
	
	if(food.isEaten(worm.getHeadPosition())) {
		worm.setBodySize(food.getFoodValue());
		score += food.getFoodValue();
	} // end if

} // end ateFood

/// displays score on the game screen
void Player::displayScore() {
	
	// nicely display ongoing score in bold
	mvaddch(0, 68, ' ');
	mvaddch(0, 69, 'S'| A_BOLD);   
	mvaddch(0, 70, 'c'| A_BOLD);
	mvaddch(0, 71, 'o'| A_BOLD);
	mvaddch(0, 72, 'r'| A_BOLD);
	mvaddch(0, 73, 'e'| A_BOLD);
	mvaddch(0, 74, ':'| A_BOLD);
	
	//converts an int to a string
	std::ostringstream convert;
	convert << score;
	std::string str = convert.str();
	
	int i;   // declared here to do mvaddch() later
	for(i = 0; i < str.size(); i++) 
		mvaddch(0, 75 + i, str[i] | A_BOLD);

	mvaddch(0, 75 + i, ' ');

} // end displayScore

/// display game title
void Player::displayGameTitle() {
	attron(A_BOLD);
	mvaddstr(0,37, " Worm ");
	attroff(A_BOLD);
} // end displayGameTitle

/// brings up a gameover screen
void Player::displayGameOver() {
	clear();  // clear the screen

	mvaddstr(5,0, "GAME OVER");
	mvaddstr(6,0, "YOU LOSE!!!!!!!!!!!!!!");
	mvaddstr(7,0, "This program will close automatically in:");	
 
	// display countdown time
	for(int i = 5; i > 0; i--) {
		mvaddch(13 - i, 41, 48 + i);
		refresh();
		sleep(1);
	} // end for

} // end displayGameOver

