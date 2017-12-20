/* 
	Name: Worm
	Date: May 21 2017
	Author: Eliahou Mayor LLC
	Copyright: May 23 2017
	Description: It's the worm game. Or snake. Or centipede. Whatever you want
	to call it. You move the worm/snake/cenitpede across the screen and try 
	to eat as much food as you can without hitting the wall or yourself.
*/

#include <ncurses.h> // to draw on screen
#include <cstring> 
#include <ctime> // for clock

#include "screen.h"
#include "worm.h"
#include "food.h"
#include "player.h"
#include "fun.h"

int main()
{
    Screen screen; // draws stuff on the screen
    Worm worm; // our hero
	Food food; // food
	Player playerOne; // player

    bool gameOver = false; // tracks game-ending conditions.

    worm.move(screen); // start the worm moving

    time_t move_start = std::time(NULL); // time of latest move

    playerOne.displayGameTitle();

    while (!gameOver) {
		
				
		while (!screen.kbhit() && !gameOver) { // if the user is silent

            // check to see if enough time has elapsed since last move
            // and move the worm if so

            if ((std::time(NULL) - move_start) >= 1) {
                if (food.isEaten(worm.getHeadPosition()))   // if ate food
					worm.setGrow(food.getFoodValue());  // how much to grow the body by
				
				worm.move(screen);  // move the worm

				playerOne.growWorm(food, worm); // if food eaten, 
				                                //grow the body accordingly
				move_start = std::time(NULL);
            } // end outer if
			
			playerOne.isGameOver(worm, gameOver); // checks if game is over
            
			food.makeFood(screen, worm);  // prints new food if old was eaten
			playerOne.displayScore();  // shows score on screen
		}
		
		if(gameOver) // if gameover, dont wait for another character to
			break;   // be entered, end the game now

        // when key is hit, use it to set worm's direction and move
		
		worm.setDirection(getch());
        if(food.isEaten(worm.getHeadPosition())) // if food is eaten
			worm.setGrow(food.getFoodValue()); // how much to grow the body by

		worm.move(screen);  // move worm
		playerOne.growWorm(food, worm); // if ate food, grow body accordingly
        move_start = std::time(NULL); 
		
        food.makeFood(screen, worm); // prints new food if old food was eaten

		playerOne.isGameOver(worm, gameOver); // checks if game is over
		playerOne.displayScore();
    } // end while
	
	playerOne.displayGameOver(); // gameover screen
	printSignature(); // signature message

	return 0;
} // end main
