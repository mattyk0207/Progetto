game: main.o Game.o Board.o Drawable.o
	gcc -o game main.o Game.o Board.o Drawable.o -lncurses

main.o: main.cpp Game.hpp Board.hpp Drawable.hpp
	gcc -c main.cpp -lncurses

Game.o: Game.cpp Board.hpp Hero.hpp
	gcc -c Game.cpp 

Board.o: Board.cpp Board.hpp Drawable.hpp Time.hpp
	gcc -c Board.cpp -lncurses 

Drawable.o: Drawable.cpp Drawable.hpp
	gcc -c Drawable.cpp -lncurses

Time.o: Time.cpp Time.hpp 
	gcc -c Time.cpp

clean:
	rm *.o game