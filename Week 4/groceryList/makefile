
PROGS := groc

all: $(PROGS)

groc: List.o Items.o ClubItems.o Main.o
	g++ -g List.o Items.o ClubItems.o Main.o -o groc

List.o: List.cpp List.hpp
	g++ -c List.cpp

Items.o: Items.cpp Items.hpp
	g++ -c Items.cpp

ClubItems.o: ClubItems.cpp ClubItems.hpp
	g++ -c ClubItems.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

clean: 
	rm -f $(PROGS) *.o *~
