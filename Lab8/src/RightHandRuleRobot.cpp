#include "../include/RightHandRuleRobot.h" 
 
void RightHandRuleRobot::move(Maze& maze) {
	const int SQUARE_NEIGHBOURS_AREA = 9;
	srand(time(0));
	int index = 0;
	char cell;
	static bool top_left = false;
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

	if (maze.getCell(std::get<0>(neighbours[1]), std::get<1>(neighbours[1])) == '*' && maze.getCell(std::get<0>(neighbours[3]), std::get<1>(neighbours[3])) == '*') {
			top_left = true;
	}

	if (maze.getCell(std::get<0>(neighbours[4]), std::get<1>(neighbours[4])) == '*' && maze.getCell(std::get<0>(neighbours[6]), std::get<1>(neighbours[6])) == '*') {
			top_left = false;
	}
    
	if (top_left) {
			if (maze.getCell(std::get<0>(neighbours[6]), std::get<1>(neighbours[6])) != '*') {
				maze.setRobot(std::get<0>(neighbours[6]), std::get<1>(neighbours[6]));
				if (maze.finished())
					return;
				neighbours = maze.getNeighbours();
				if (maze.getCell(std::get<0>(neighbours[3]), std::get<1>(neighbours[3])) != '*') {
					top_left = false;
					maze.setRobot(std::get<0>(neighbours[3]), std::get<1>(neighbours[3]));
				}
				return;
			}
			else {
				if (maze.getCell(std::get<0>(neighbours[7]), std::get<1>(neighbours[7])) != '*') {
					maze.setRobot(std::get<0>(neighbours[7]), std::get<1>(neighbours[7]));
					return;
				}
				else {
					maze.setRobot(std::get<0>(neighbours[4]), std::get<1>(neighbours[4]));
					return;
				}
			}
		return;
	}

	if (maze.getCell(std::get<0>(neighbours[4]), std::get<1>(neighbours[4])) == 'E') {
		maze.setRobot(std::get<0>(neighbours[4]), std::get<1>(neighbours[4]));
		return;
	}

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
		if (maze.getCell(std::get<0>(neighbours[4]), std::get<1>(neighbours[4])) != '*') {
			maze.setRobot(std::get<0>(neighbours[4]), std::get<1>(neighbours[4]));
			return;
		}

		if (maze.getCell(std::get<0>(neighbours[2]), std::get<1>(neighbours[2])) != '*') {
			maze.setRobot(std::get<0>(neighbours[2]), std::get<1>(neighbours[2]));
			return;
		}

		else {
			maze.setRobot(std::get<0>(neighbours[1]), std::get<1>(neighbours[1]));	
			return;	
		}
	}
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