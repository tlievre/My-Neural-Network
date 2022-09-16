# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).o perceptron.o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o perceptron.o

$(TARGET).o: $(TARGET).cpp perceptron.hpp
	$(CC) $(CFLAGS) -c main.cpp

perceptron.o: perceptron.cpp perceptron.hpp
	$(CC) $(CFLAGS) -c perceptron.cpp

clean:
	$(RM) $(TARGET) *.o
