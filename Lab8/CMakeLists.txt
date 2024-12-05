cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(maze)

include_directories(include, src)

add_library(maze
	include/Maze.h
	src/Maze.cpp
)

add_library(robot
	include/Robot.h
	src/Robot.cpp
)

add_library(random_robot
	include/RandomRobot.h
	src/RandomRobot.cpp
)

add_library(right_hand_rule
	include/RightHandRuleRobot.h
	src/RightHandRuleRobot.cpp
)

add_executable(main
	main.cpp
)

target_link_libraries(main
	maze
	robot
	random_robot
	right_hand_rule
)