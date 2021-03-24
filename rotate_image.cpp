//anki - march 23
// https://leetcode.com/problems/rotate-image/
#include <vector>
#include <algorithm>
using namespace std; 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n  = matrix.size(); 
        //transpose then rotate
        //transpose: 
        for(int row = 0; row < n; ++row){
            for(int col = 0; col < n; ++col){
                if(row < col){
                    int temp = matrix[row][col]; 
                    matrix[row][col] = matrix[col][row]; 
                    matrix[col][row] = temp;
                }
            }
        }//outer for transpose

        //rotate:
        for(int row = 0; row < n; ++row){
            for(int col = 0; col < n/2; ++col){
                std::swap(matrix[row][col], matrix[row][n-col-1]); 
            }//inner
        }
    }
};//solution class
