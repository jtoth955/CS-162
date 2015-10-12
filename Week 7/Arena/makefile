
PROGS := Character

all: $(PROGS)

Character: Character.h Arena.o Barbarian.o Blue.o Goblin.o Reptile.o Shadow.o Main.o
	g++ -g Character.h Arena.o Barbarian.o Blue.o Goblin.o Reptile.o Shadow.o Main.o -o  Character

Arena.o: Arena.cpp Arena.h Character.h
	g++ -c Arena.cpp

Barbarian.o: Barbarian.cpp Barbarian.h
	g++ -c Barbarian.cpp

Blue.o: Blue.cpp Blue.h
	g++ -c Blue.cpp

Goblin.o: Goblin.cpp Goblin.h
	g++ -c Goblin.cpp

Reptile.o: Reptile.cpp Reptile.h
	g++ -c Reptile.cpp

Shadow.o: Shadow.cpp Shadow.h
	g++ -c Shadow.cpp

Main.o: Main.cpp 
	g++ -c Main.cpp


clean: 
	rm -f $(PROGS) *.o *~