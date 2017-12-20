#include "food.h" 

#include <iostream>
#include <cstdlib>

/// Gives the food a random value 
void Food::valueGenerator() {
	srand(time(NULL));
	
	foodValue = rand() % 9 + 1;  // generates random value between 1 and 9
	foodSymbol = (char) foodValue + 48;

} // end valueGenerator

/// gives the food a random legal position
void Food::positionGenerator(Position head, Position *body, int size) {
	srand(time(NULL));
	
	const int xRange = 78;
	const int yRange = 22;

	// gives random values within the walls of the screen
	foodPosition.X = rand() % xRange + 1;
	foodPosition.Y = rand() % yRange + 1;

	// checks if food's position is coincidental with snake body
	for(int i = 0; i < size; i++) 
		while((foodPosition == body[i]) || foodPosition == head) {

			foodPosition.X = rand() % xRange + 1;
			foodPosition.Y = rand() % yRange + 1;
			i = 0;
		} // end while

} // end positionGenerator

/// checks if the snake ate the food
bool Food::isEaten(Position head) {
	if(head == foodPosition)  // checks if head position is on food
		return true;
	
	return false;

} // end isEaten

/// does everything ecessary to put food on the screen
void Food::makeFood(Screen &screen, Worm &worm) {
	Position head = worm.getHeadPosition();
	Position *body = worm.getBodyPosition();
	int size = worm.getBodySize();
	
	if(isEaten(head) || foodValue == 0) {
		valueGenerator();   
		positionGenerator(head, body, size);
		screen.drawChar(foodPosition.X, foodPosition.Y, foodSymbol);
	} // end if 

} // end printFood

