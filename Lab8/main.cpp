#include <iostream>
#include <tuple>

#include "include/Maze.h"
#include "include/Robot.h"
#include "include/RandomRobot.h"
#include "include/RightHandRuleRobot.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Usage: ./main <maze.txt>\n";
		return -1;
	}
	Maze maze = Maze(argv[1]); // S at pos: {6, 3}
	std::vector<std::tuple<int, int> > neighbours = maze.getNeighbours();
	int i = std::get<0>(neighbours[4]);
	int j = std::get<1>(neighbours[4]);
	std::cout << i << " " << j << "\n";
	maze.print();
	RightHandRuleRobot r = RightHandRuleRobot();
	// while (!maze.finished()){
		r.move(maze);

		std::cout << "\n";
		maze.print();
	// }


	return 0;
}