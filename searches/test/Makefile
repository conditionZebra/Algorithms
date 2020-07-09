all: testBinary.cpp
	cd ../../lib && make -f ../lib/Makefile
	g++ -std=c++0x -I../../lib ../../lib/eulerlib.o testBinary.cpp 

clean:
	rm a.out
