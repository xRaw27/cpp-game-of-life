CC = g++
FLAGS = -std=c++17 -Wall -Wextra -pedantic
SRC = src/main.cpp src/GUI.cpp src/InputReader.cpp src/Game.cpp
OUT = game_of_life

compile:
	$(CC) $(FLAGS) $(SRC) -lSDL2 -o $(OUT)

all: compile
	./$(OUT)

clean:
	rm -f $(OUT)