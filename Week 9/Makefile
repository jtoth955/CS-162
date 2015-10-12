
PROGS := iterativeFib recursiveFib factorials


all: $(PROGS)

iterativeFib: iterativeFib.cpp
	g++ -O2 -std=c++0x -g iterativeFib.cpp -o iterativeFib

recursiveFib: recursiveFib.cpp
	g++ -O2 -std=c++0x -g recursiveFib.cpp -o recursiveFib 
	
factorials: factorials.cpp
	g++ -O1 -std=c++0x -g factorials.cpp -o factorials

clean: 
	rm -f $(PROGS) *.o *~