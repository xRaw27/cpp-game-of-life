CC = g++
FLAGS = -std=c++17 -Wall -Wextra -pedantic
SRC = src/main.cpp src/GUI.cpp src/InputReader.cpp

compile:
	$(CC) $(FLAGS) $(SRC) -lSDL2 -o main

all: compile
	./main
