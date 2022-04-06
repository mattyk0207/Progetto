all: testFile

main: testFile.cpp 
	g++ test testFile.cpp  -lncurses 

clean:
	rm *.o testFile