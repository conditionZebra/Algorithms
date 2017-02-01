all: testBinary.cpp
	cd ../../../euler/lib && make -f ../lib/Makefile
	g++ -std=c++0x -I../../../euler/lib ../../../euler/lib/eulerlib.o testBinary.cpp 

clean:
	rm a.out
