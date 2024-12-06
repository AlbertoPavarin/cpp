#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <string>
#include <tuple>


class Maze{
	private:
		static const int N_COLUMN = 9; 
		static const int N_ROW = 9; 
		int i_exit; // row
		int j_exit; // column
		int i_robot; // row
		int j_robot; // column
		std::vector<std::vector<char> > m;
		void buildMaze(std::string path);
	public:
		Maze(std::string path);
		void print() const;
		bool finished() { return ((i_exit == i_robot) && (j_exit == j_robot)); }
		void setRobot(int i, int j);
		int getIRobot() const;
		int getJRobot() const;
		int getIExit() const;
		int getJExit() const;
		int getNRow() const { return N_ROW; }
		int getNCol() const { return N_COLUMN; }
		char getCell(int i, int j) const { return m[i][j]; }
		std::vector<std::tuple<int, int> > getNeighbours() const; // get the 8 cells near the robot
};

#endif