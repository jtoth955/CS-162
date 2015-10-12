
PROGS := Character

all: $(PROGS)

Character: Character.hpp Arena.o Barbarian.o Blue.o Goblin.o Reptile.o Shadow.o Main.o
	g++ -g Character.hpp Arena.o Barbarian.o Blue.o Goblin.o Reptile.o Shadow.o Main.o -o  Character

Arena.o: Arena.cpp Arena.hpp Character.hpp
	g++ -c Arena.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp

Blue.o: Blue.cpp Blue.hpp
	g++ -c Blue.cpp

Goblin.o: Goblin.cpp Goblin.hpp
	g++ -c Goblin.cpp

Reptile.o: Reptile.cpp Reptile.hpp
	g++ -c Reptile.cpp

Shadow.o: Shadow.cpp Shadow.hpp
	g++ -c Shadow.cpp

Main.o: Main.cpp 
	g++ -c Main.cpp


clean: 
	rm -f $(PROGS) *.o *~