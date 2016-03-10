#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
class PathfinderInterface
{
	public:
		PathfinderInterface(){}
		virtual ~PathfinderInterface(){}
		
		virtual string getMaze() = 0;
		virtual void createRandomMaze() = 0;
		virtual bool importMaze(string file_name) = 0;
		virtual vector<string> solveMaze() = 0;
		//-----------------------------------------------------------------------------------------
		
	private:
		const int GRID_SIZE = 5;
		int maze[GRID_SIZE][GRID_SIZE][GRID_SIZE];
};
