//Anki April 8 
//Number of Islands

#include <vector> 
#include <stack>
#include <cassert> 
using namespace std; 

class Solution{
    private: 
    char current = '0'; 
    int islandCount = 0; 
    stack<std::pair<int, int>> theStack;  
    public: 

    void dfs(vector<vector<char>>& grid){
        if(theStack.empty()){
            return; 
        }

        auto x = theStack.top(); 
        theStack.pop();
        if(x.second + 1 < grid[0].size()){
            theStack.push(std::make_pair(x.first, x.second+1)); 
            dfs()
        }

    }
    int numIslands(vector<vector<char>>& grid){
        int row = 0; 
        int col = 0; 
        while(row++ < grid.size()){
            while(col ++ < grid[0].size()){
                if(current == '0' && grid[row][col] == '1'){
                    ++islandCount;
                    theStack.push(std::make_pair(row,col));  
                    dfs(grid); 
                }
            }//inner
        }//outer
    }//func
};