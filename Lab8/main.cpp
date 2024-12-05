#include <iostream>

#include "include/Maze.h"
#include "include/Robot.h"
#include "include/RandomRobot.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Usage: ./main <maze.txt>\n";
		return -1;
	}
	Maze maze = Maze(argv[1]);

	maze.print();

	RandomRobot r = RandomRobot();
	r.move(maze);


	return 0;
}