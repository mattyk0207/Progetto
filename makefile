game: main.o Game.o Room.o
	gcc -o game main.o Game.o Room.o -lncurses

main.o: main.cpp Game.hpp Room.hpp
	gcc -c main.cpp -lncurses

Game.o: Game.cpp Game.hpp
	gcc -c Game.cpp

Room.o: Room.cpp Room.hpp RoomTemplates.hpp
	gcc -c Room.cpp -lncurses

clean:
	rm *.o game