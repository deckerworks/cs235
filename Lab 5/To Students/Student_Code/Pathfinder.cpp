#include "Pathfinder.h"    
    
    
    Pathfinder::Pathfinder(){
        //create default maze
        for (int x = 0; x < GRID_SIZE; x ++) {
            for (int y = 0; y < GRID_SIZE; y++){
                for (int z = 0; z < GRID_SIZE; z++){
                    maze[x][y][z] = 1;
                }
            }
        }
        
    };
    
    string Pathfinder::getMaze(){
        stringstream stringmaze;
        
        for (int x = 0; x < GRID_SIZE; x ++) {
            for (int y = 0; y < GRID_SIZE; y++){
                for (int z = 0; z < GRID_SIZE; z++){
                    stringmaze << maze[x][y][z] << " ";
                }
            }
        }
        return stringmaze.str();
    };
    
	void Pathfinder::createRandomMaze(){
	    
	    for (int x = 0; x < GRID_SIZE; x ++) {
            for (int y = 0; y < GRID_SIZE; y++){
                for (int z = 0; z < GRID_SIZE; z++){
                    
                    if (x == 0 && y == 0 && z == 0){
                        maze[x][y][z] = 1;
                    }
                    else if(x == (GRID_SIZE - 1) && y == (GRID_SIZE - 1) && z == (GRID_SIZE - 1))
                        maze[x][y][z] = 1;
                    else {
                        maze[x][y][z] = rand() % 2;
                    }
                }
            }
        }
	};
	
	bool Pathfinder::importMaze(string file_name){
	    
	    ifstream in_file;
	    in_file.open(file_name.c_str());
	    
	    
	    //file failed to open
	    if (in_file.fail()){
	        in_file.clear();
	        return false;
	    }
	    else{
	        int length = 0;
	        int temp[GRID_SIZE][GRID_SIZE][GRID_SIZE];
	        int token;
	        for (int x = 0; x < GRID_SIZE; x ++) {
                for (int y = 0; y < GRID_SIZE; y++){
                    for (int z = 0; z < GRID_SIZE; z++){
                        //as long as we aren't at the end of the file and the length is less than our grid size
                        //add the new token to the maze
                        if (!in_file.eof() && length < GRID_SIZE * GRID_SIZE * GRID_SIZE){
                            in_file >> token;
                            temp[x][y][z] = token;
                            length++;
                            }
                            else{
                                return false;
                            }
                        }
                    }
                }
            
            if (temp[0][0][0] != 1 || temp[4][4][4] != 1 || !in_file.eof() ){
                return false;
            }
            else {
                //copy the temporary cube to the main cube
                for (int x = 0; x < GRID_SIZE; x ++) {
                    for (int y = 0; y < GRID_SIZE; y++){
                        for (int z = 0; z < GRID_SIZE; z++){
                            maze[x][y][z] = temp[x][y][z];
                        }
                    }
                }
            }
            //close the opened file and return
            in_file.close();
            return true;
	    }
    };
	
	vector<string> Pathfinder::solveMaze(){
	    //make sure there is nothing in the results before we start
	    mazeresult.clear();
	    
	    if (solveMaze(0,0,0)){
            reverse(mazeresult.begin(), mazeresult.end());
	        //return mazeresult;
	    }
	    else{
	        mazeresult.clear();
	        //return mazeresult;
	    }
	    
	    // restore original (valid) maze values and return result
        for (int x = 0; x < GRID_SIZE; x ++) {
            for (int y = 0; y < GRID_SIZE; y++){
                for (int z = 0; z < GRID_SIZE; z++){
                    if (maze[x][y][z] == 7)
                    maze[x][y][z] = 1;
                }
            }
        }
        return mazeresult;
	};
	
	bool Pathfinder::solveMaze(int x, int y, int z){
	    // number is marked to 7 if on the path
	    // number is marked as 1 if on a path not visited
	    // number is marked as 0 if a barrier
	    
	    // cell is out of bounds
	    if (x < 0 || y < 0 || z < 0 ||
	        x > 4 || y > 4 || z > 4) {
	        return false;
	    }
	    else if ( x == 4 && y == 4 && z == 4) {
	        add_to_result(x, y, z); //cell is on the path
	        return true;            //cell is also maze exit
	    }
	    // cell cell is a barrier or dead end
	    else if(maze[x][y][z] != 1) {
	        return false;
	    }
	    else {
	        // the recursive case
	        // attempt to find a path from each neighbor
	        // tentatively mark cell as on path
	        maze[x][y][z] = 7;
	        
	        if (   solveMaze(x + 1, y, z) || solveMaze(x - 1, y, z)
	            || solveMaze(x, y + 1, z) || solveMaze(x, y - 1, z)
	            || solveMaze(x, y, z + 1) || solveMaze(x, y, z - 1)){
                add_to_result(x, y, z);
                return true;
	        }
	        else {
	            return false;
	        }
	    }
	    
	};
	
	void Pathfinder::add_to_result(int x, int y, int z){
	    stringstream path_point;
	    path_point << "(" << x << ", " << y << ", " << z << ")";
	    mazeresult.push_back(path_point.str());
	};