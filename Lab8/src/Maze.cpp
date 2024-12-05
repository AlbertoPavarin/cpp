#include "../include/Maze.h"

#include <iostream>
#include <fstream>


Maze::Maze(std::string path) {
	path = "../" + path;
	std::fstream fs = std::fstream();
	fs.open(path, std::fstream::in);
	if (fs.fail())
		std::cout << "STOPPPP!!!!\n";
	fs.close();
}