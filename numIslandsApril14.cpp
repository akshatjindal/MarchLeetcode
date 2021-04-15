#include <vector>
#include <stack>
#include <cassert> 

using namespace std; 

class Solution {
    private:
    int islandCount = 0; 
    int numRows = -1; 
    int numCols = -1;  
    stack<pair<int,int>> island; 
public:

    int numIslands(vector<vector<char>>& grid) {
        numRows= grid.size(); 
        numCols = grid[0].size(); 

        for(int row = 0; row < numRows; row++){
            for(int col = 0; col < numCols; col++){
                if(grid[row][col] == '1'){
                    ++islandCount;
                    assert(island.empty()); 
                    island.push(std::make_pair(row,col)); 
                    while(!island.empty()){
                        auto coordinate = island.top(); 
                        island.pop(); 
                        
                        if(grid[coordinate.first][coordinate.second] == '0')
                            continue; 
                        
                        grid[coordinate.first][coordinate.second] = '0'; 

                        if(coordinate.first+1 < numRows){
                            pair<int,int> temp = std::make_pair(coordinate.first + 1, coordinate.second); 
                            island.push(temp); 
                        }

                        if(coordinate.first-1 >= 0){
                            pair<int,int> temp = std::make_pair(coordinate.first -1, coordinate.second); 
                            island.push(temp); 
                        }

                        if(coordinate.second-1 >= 0){
                            pair<int,int> temp = std::make_pair(coordinate.first, coordinate.second-1); 
                            island.push(temp); 
                        }

                        if(coordinate.second+1 < numCols){
                            pair<int,int> temp = std::make_pair(coordinate.first, coordinate.second+1); 
                            island.push(temp); 
                        }

                        
                    }//while island isnt empty
                }
            }//inner
        }//outer

        return islandCount; 
    }//func
};
