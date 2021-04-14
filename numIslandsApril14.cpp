#include <vector>

using namespace std; 

class Solution {
    private:
    int islandCount = 0; 
    int numRows = -1; 
    int numCols = -1;  
    
public:

    void helper(int row, int col, vector<vector<char>>& matrix){
        if(matrix[row][col] == '0')
            return; 

        matrix[row][col] = '0'; 
        

        if(row+1 < numRows){
            helper(row+1, col, matrix); 
        }

        if(col + 1 < numCols){
            helper(row, col+1,matrix); 

        }

        if(col -1 >= 0 ){
         helper(row, col-1,matrix); 
        }

        if(row-1 >= 0 ){
         helper(row-1, col,matrix); 
        }
    }//func

    int numIslands(vector<vector<char>>& grid) {
        numRows= grid.size(); 
        numCols = grid[0].size(); 

        for(int row = 0; row < numRows; row++){
            for(int col = 0; col < numCols; col++){
                if(grid[row][col] == '1'){
                    ++islandCount ;
                    helper(row, col, grid); 
                }
            }//inner
        }//outer

        return islandCount; 
    }//func
};
