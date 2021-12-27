all: 
	cd ../lib && make -f ../lib/Makefile
	g++ -std=c++0x 1.cpp -o 1 
	g++ -std=c++0x 2.cpp -o 2 
	g++ -std=c++0x -I../lib ../lib/eulerlib.o 3.cpp -o 3 
	g++ -std=c++0x -I../lib ../lib/eulerlib.o 4.cpp -o 4 
	g++ -std=c++0x -Wno-psabi -I../lib ../lib/eulerlib.o 5.cpp -o 5 
	g++ -std=c++0x 6.cpp -o 6
	g++ -std=c++0x -I../lib ../lib/eulerlib.o 7.cpp -o 7
	g++ -std=c++0x -I../lib ../lib/eulerlib.o 8.cpp -o 8
	g++ -std=c++0x 9.cpp -o 9 
	g++ -std=c++0x -I../lib ../lib/eulerlib.o 10_naive.cpp -o 10_naive
	g++ -std=c++0x 10_sophisticated.cpp -o 10_sophisticated
	g++ -std=c++0x 10_sophisticated_array.cpp -o 10_sophisticated_array
	g++ -std=c++0x 10_sophisticated_std_array.cpp -o 10_sophisticated_std_array
	g++ -std=c++0x -I../lib ../lib/eulerlib.o 11.cpp -o 11
	g++ -std=c++0x -Wno-psabi -I../lib ../lib/eulerlib.o 12.cpp -o 12 
	
	g++ -std=c++0x -I../lib ../lib/eulerlib.o 24.cpp -o 24 
	g++ -std=c++0x 25.cpp -o 25 
	g++ -std=c++0x 26.cpp -o 26 
	g++ -std=c++0x -I../lib ../lib/eulerlib.o 27.cpp -o 27 

.PHONY : clean
clean :
	find . -type f -executable -delete
