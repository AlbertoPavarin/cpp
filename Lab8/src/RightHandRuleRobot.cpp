#include "../include/RightHandRuleRobot.h" 
 
void RightHandRuleRobot::move(Maze& maze) {
	const int SQUARE_NEIGHBOURS_AREA = 9;
	srand(time(0));
	int index = 0;
	char cell;
	bool valid = false;
	std::vector<std::tuple<int, int> > neighbours = maze.getNeighbours();
	int i = std::get<0>(neighbours[4]);
	int j = std::get<1>(neighbours[4]);
	initialSetup(i, j, maze, neighbours);
};

void RightHandRuleRobot::initialSetup(int i, int j, Maze& maze, std::vector<std::tuple<int, int> > neighbours){
	while (true) {
		neighbours = maze.getNeighbours();
		i = std::get<0>(neighbours[4]);
		j = std::get<1>(neighbours[4]);
		if(maze.getCell(i, j) == '*')
			break;
		maze.setRobot(i, j);
	}
}