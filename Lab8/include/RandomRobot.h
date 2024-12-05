#ifndef RANDOM_ROBOT_H
#define RANDOM_ROBOT_H

#include "Robot.h"
#include "Maze.h"

class RandomRobot: Robot{
	private:

	public:
		RandomRobot(){}
		void move(Maze& maze) override;
};

#endif