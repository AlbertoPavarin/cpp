#ifndef RIGHT_HAND_RULE_ROBOT_H
#define RIGHT_HAND_RULE_ROBOT_H

#include "Robot.h"
#include "Maze.h"


class RightHandRuleRobot : Robot{
	private:
	bool setupped;
		void initialSetup(int i, int j, Maze& maze, std::vector<std::tuple<int, int> > neighbours);
	public:
		RightHandRuleRobot(): setupped {false} {}
		void move(Maze& maze) override;
};

#endif