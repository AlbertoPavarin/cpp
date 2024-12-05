#include "../include/Maze.h"

#include <iostream>
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