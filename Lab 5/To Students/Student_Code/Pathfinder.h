#ifndef PATHFINDER_H_
#define PATHFINDER_H_
#include "PathfinderInterface.h"
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Pathfinder : public PathfinderInterface {
	public:
		Pathfinder();
		virtual ~Pathfinder(){};
		virtual string getMaze();
		virtual void createRandomMaze();
		virtual bool importMaze(string file_name);
		virtual vector<string> solveMaze();
		//-----------------------------------------------------------------------------------------
		
	private:
		vector<string> mazeresult;
		static const int GRID_SIZE = 5;
		int maze[GRID_SIZE][GRID_SIZE][GRID_SIZE];
		bool solveMaze(int x, int y, int z);
		void add_to_result(int x, int y, int z);
		
};
#endif