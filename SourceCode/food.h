#ifndef FOOD_H
#define FOOD_H

#include "worm.h"
#include "screen.h"
#include "position.h"

class Food {
	private: 
		Position foodPosition; // contains food's position
		char foodSymbol; // symbol of food
		int foodValue;   // food's value
		void positionGenerator(Position, Position*, int);
		void valueGenerator();
	public:
		Food() { foodValue = 0; } 
		void makeFood(Screen &, Worm &); 
		int getFoodValue() { return foodValue; }
		bool isEaten(Position); 

};
#endif
