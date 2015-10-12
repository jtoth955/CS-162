
PROGS := stack queue

all: $(PROGS)

stack: Stack.o stackMain.o
	g++ -g Stack.o stackMain.o -o stack

stack.o: Stack.cpp Stack.h 
	g++ -c Stack.cpp 

stackMain.o: stackMain.cpp
	g++ -c stackMain.cpp

queue: Queue.o Main.o
	g++ -g Queue.o Main.o -o queue

queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

main.o: Main.cpp 
	g++ -c Main.cpp



clean: 
	rm -f $(PROGS) *.o *~