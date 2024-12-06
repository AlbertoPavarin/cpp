#include <tuple>

#include "../include/RandomRobot.h" 
 
void RandomRobot::move(Maze& maze) {
	const int SQUARE_NEIGHBOURS_AREA = 9;
	srand(time(0));
	int index = 0;
	int i = 0;
	int j = 0;
	char cell;
	bool valid = false;
	std::vector<std::tuple<int, int> > neighbours = maze.getNeighbours();
	while (!valid) {
		index = rand() % SQUARE_NEIGHBOURS_AREA;
		std::cout << index << "\n";
		i = std::get<0>(neighbours[index]);
		j = std::get<1>(neighbours[index]);
		cell = maze.getCell(i, j);
		std::cout << "i: " << i << " j: " << j << "\n";
		if (cell != '*')
			valid = true;
	}

	maze.setRobot(i, j);
};