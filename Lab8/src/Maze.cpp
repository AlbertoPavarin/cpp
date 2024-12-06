#include "../include/Maze.h"

#include <iostream>
#include <tuple>
#include <fstream>


Maze::Maze(std::string path) {
	path = "../" + path;
	m.resize(N_ROW, std::vector<char>(N_COLUMN));
	buildMaze(path);
}

void Maze::buildMaze(std::string path){
	std::fstream fs = std::fstream();
	char c;
	int i = 0, j = 0;
	fs.open(path, std::fstream::in);
	if (fs.fail())
		std::cout << "STOPPPP!!!!\n";

	while (fs.get(c))
	{
		if (c == '\n')
		{
			i++;
			j = 0;
		}

		if (c == 'S') {
			i_robot = i;
			j_robot = j;
		}

		if (c == 'E') {
			i_exit = i;
			j_exit = j;
		}

		if (c != '\n')
			m[i][j++] = c;
	}

	fs.close();
}

void Maze::print() const{
	for (int i = 0; i < N_ROW; i++)
	{
		for (int j = 0; j < N_COLUMN; j++)
		{
			std::cout << m[i][j];
		}
		std::cout << "\n";
	}
	
}

void Maze::setRobot(int i, int j) {
	m[i_robot][j_robot] = ' ';
	i_robot = i;
	j_robot = j;
	m[i_robot][j_robot] = 'S';
}

int Maze::getIRobot() const {
	return i_robot;
}

int Maze::getJRobot() const {
	return j_robot;
}

int Maze::getIExit() const {
	return i_exit;
}

int Maze::getJExit() const {
	return j_exit;
}

// return order:
//	0 -> top-left, 1 -> top-cnt, 2 -> top-right
//  3 -> left 4 -> right
//	5 -> bottom-left, 6 -> bottom-cnt, 7 -> bottom-right
std::vector<std::tuple<int, int>> Maze::getNeighbours() const { // get the 8 cells near the robot
	std::vector<std::tuple<int, int> > p;
	
	for (int i = i_robot - 1; i <= i_robot + 1; i++) {
		// p.push_back({i-1, j_robot-1});
		for (int j = j_robot - 1; j <= j_robot +1; j++) {
			if (j != j_robot || i_robot != i) {
				i >= N_ROW ? i = -1 : i = i;
				j >= N_COLUMN ? i = -1 : j = j;
				p.push_back({i, j});
			}
		}
	}

	return p;
} 