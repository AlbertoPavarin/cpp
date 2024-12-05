#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <string>

class Maze{
	private:
		void readFile(std::string path);
	public:
		Maze(std::string path);
};

#endif