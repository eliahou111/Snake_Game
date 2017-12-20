#ifndef PLAYER_H
#define PLAYER_H

#include "worm.h"
#include "food.h"

class Player
{
	private:
		int score; // ongoing score
	public:
		Player() { score = 0; }
		void isGameOver(Worm &, bool &);
		void growWorm(Food & , Worm &);
		void displayScore();
		int getScore() { return score; }
		void displayGameOver ();
		void displayGameTitle();
};

#endif
