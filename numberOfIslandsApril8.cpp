//Anki April 8 
//Number of Islands

#include <vector> 
#include <stack>
#include <cassert> 
using namespace std; 

class Solution{
    private: 
    int islandCount = 0; 
    int numCols = 0; 
    int numRows = 0; 
    public: 

    void dfs(vector<vector<char>>& grid, int row, int col){
        //base case
        if(grid[row][col] == '0'){
            return; 
        }
        
        if(col + 1 < numCols){
            dfs(grid, row, col+1); 
        }

        if(row + 1 < numRows){
            dfs(grid, row+1, col); 
        }

        if(row + 1 < numRows && col - 1 >= 0){
            dfs(grid, row+1, col-1); 
        }

        if(row + 1 < numRows && col + 1 < numCols){
            dfs(grid, row+1, col+1); 
        }


        grid[row][col] = '0'; 
    }
    int numIslands(vector<vector<char>>& grid){
        int row = 0; 
        int col = 0; 
        numCols = grid[0].size(); 
        numRows = grid.size(); 
        while(row++ < numRows){
            while(col ++ < numCols){
                if(grid[row][col] == '1'){
                    ++islandCount;
                    dfs(grid, row, col); 
                }
            }//inner
        }//outer

    return islandCount; 
    }//func
};