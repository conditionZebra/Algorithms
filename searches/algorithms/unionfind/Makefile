# build an executable named myprog from myprog.c

 # the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -std=c++0x -g -Wall

# the build target executable:
TARGET = test

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp executor.cpp ufBaseClass.cpp ufQuick.cpp ufWeighted.cpp ufQuickUnion.cpp

clean:
	$(RM) $(TARGET)
