game: game.o screen.o worm.o food.o player.o fun.o 
	g++ game.o screen.o food.o worm.o player.o fun.o -lncurses -o game

game.o: game.cpp screen.h worm.h player.h fun.h position.h
	g++ -c -g game.cpp
screen.o: screen.cpp screen.h
	g++ -c -g screen.cpp
worm.o: worm.cpp worm.h screen.h position.h
	g++ -c -g worm.cpp
food.o: food.cpp food.h worm.h screen.h position.h
	g++ -c -g food.cpp
player.o: player.cpp player.h food.h worm.h
	g++ -c -g player.cpp
fun.o: fun.cpp fun.h
	g++ -c -g fun.cpp
clean:
	rm *.o game
