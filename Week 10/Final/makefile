
PROGS := Final

all: $(PROGS)

Final: Room.o Baggage.o Passenger.o Engine.o Game.o Main.o
	g++ -g Room.o Baggage.o Passenger.o Engine.o Game.o Main.o -o Final

Room.o: Room.cpp Room.h
	g++ -c Room.cpp

Baggage.o: Baggage.cpp Baggage.h 
	g++ -c Baggage.cpp

Passenger.o: Passenger.cpp Passenger.h
	g++ -c Passenger.cpp

Engine.o: Engine.cpp Engine.h
	g++	-c Engine.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

clean: 
	rm -f $(PROGS) *.o *~
