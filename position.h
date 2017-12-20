#ifndef POSITION_H
#define POSITION_H

/// position class for food's position and worm's position
class Position {

	public:	
		int X;
		int Y;
		bool operator==(Position a) {
			if(this ->X == a.X && this->Y == a.Y)
				return true;
			return false;
		}
};


#endif
