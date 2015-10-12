
PROGS := FileFilter

all: $(PROGS)

FileFilter: FileFilter.hpp Copy.o Encrypt.o Special.o Transform.o Main.o
	g++ -g FileFilter.hpp Copy.o Encrypt.o Special.o Transform.o Main.o -o FileFilter

Copy.o: Copy.cpp FileFilter.hpp
	g++ -c Copy.cpp

Encrypt.o: Encrypt.cpp
	g++ -c Encrypt.cpp

Special.o: Special.cpp
	g++ -c Special.cpp

Transform.o: Transform.cpp
	g++ -c Transform.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

clean: 
	rm -f $(PROGS) *.o *~	