cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(maze)

include_directories(include, src)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_EXTENSIONS false)

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