all: main

main: main.cpp 
	g++ main.cpp  -lncurses  

clean:
	rm *.o main