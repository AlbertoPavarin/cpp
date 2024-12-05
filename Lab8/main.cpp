#include <iostream>

#include "include/Maze.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Usage: ./main <maze.txt>\n";
		return -1;
	}
	
	Maze maze = Maze(argv[1]);
	
	return 0;
}