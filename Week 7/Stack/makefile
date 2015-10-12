
PROGS := file

file: Stack.o Main.o
	g++ -g Stack.o Main.o -o file

stack.o: Stack.cpp Stack.h 
	g++ -c Stack.cpp 

main.o: Main.cpp
	g++ -c Main.cpp

clean: 
	rm -f $(PROGS) *.o*~