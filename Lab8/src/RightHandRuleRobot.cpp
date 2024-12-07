#include "../include/RightHandRuleRobot.h" 
 
void RightHandRuleRobot::move(Maze& maze) {
	const int SQUARE_NEIGHBOURS_AREA = 9;
	srand(time(0));
	int index = 0;
	char cell;
	bool valid = false;
	std::vector<std::tuple<int, int> > neighbours = maze.getNeighbours();
	int i_right = std::get<0>(neighbours[4]);
	int j_right = std::get<1>(neighbours[4]);
	if(!setupped)
	{
			initialSetup(i_right, j_right, maze, neighbours);
			return;
	}

	neighbours = maze.getNeighbours();
	std::cout << maze.getCell(std::get<0>(neighbours[2]), std::get<1>(neighbours[2])) << "\n";

	if (maze.getCell(std::get<0>(neighbours[1]), std::get<1>(neighbours[1])) == '*') {
		if (maze.getCell(std::get<0>(neighbours[0]), std::get<1>(neighbours[0])) != '*') {
			maze.setRobot(std::get<0>(neighbours[0]), std::get<1>(neighbours[0]));
			return;
		}
		else {
			maze.setRobot(std::get<0>(neighbours[3]), std::get<1>(neighbours[3]));	
			return;	
		}
	}	

	if (maze.getCell(std::get<0>(neighbours[1]), std::get<1>(neighbours[1])) != '*') {
		if (maze.getCell(std::get<0>(neighbours[2]), std::get<1>(neighbours[2])) != '*') {
			maze.setRobot(std::get<0>(neighbours[2]), std::get<1>(neighbours[2]));
			return;
		}
		else {
			maze.setRobot(std::get<0>(neighbours[1]), std::get<1>(neighbours[1]));	
			return;	
		}
	}



	// while (true)
	// {
	// 	neighbours = maze.getNeighbours();
	// 	i_right = std::get<0>(neighbours[4]);
	// 	j_right = std::get<1>(neighbours[4]);
	// 	i_top = std::get<0>(neighbours[1]);
	// 	j_top = std::get<1>(neighbours[1]);
	// 	if(maze.getCell(i_top, j_top) != '*' || maze.getCell(i_right, j_right) != '*')
	// 		maze.setRobot(i_top, j_top);
	// 	// else
	// 	// 	maze.setRobot(std::get<0>(neighbours[3]), std::get<1>(neighbours[3]));
	// }
	
};

void RightHandRuleRobot::initialSetup(int i, int j, Maze& maze, std::vector<std::tuple<int, int> > neighbours){
	while (true) {
		neighbours = maze.getNeighbours();
		i = std::get<0>(neighbours[4]);
		j = std::get<1>(neighbours[4]);
		if(maze.getCell(i, j) == '*')
			break;
		maze.setRobot(i, j);
		setupped = true;
	}
}