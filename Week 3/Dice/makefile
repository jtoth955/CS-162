
PROGS := die

all: $(PROGS)

die: Dice.o LoadedDice.o Main.o
	g++ -g Dice.o LoadedDice.o Main.o -o die 

Dice.o: Dice.cpp Dice.hpp
	g++ -c Dice.cpp

LoadedDice.o: LoadedDice.cpp LoadedDice.hpp
	g++ -c LoadedDice.cpp

Main.o: Main.cpp
	g++ -c Main.cpp


clean: 
	rm -f $(PROGS) *.o *~


