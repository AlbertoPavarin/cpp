#ifndef ROBOT_H
#define ROBOT_H

#include "Maze.h"


class Robot{
	private:

	public:
		virtual void move(Maze& maze) = 0;
};

#endif