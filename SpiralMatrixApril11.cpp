#include <vector>
using namespace std; 

class Solution {
    private: 
    int n = -1; 
    int m = -1; 
    bool validRange(std::pair<int, int> &start, std::pair<int, int> &finish){
        bool flag = true; 
        if(start.first < 0 || start.first >= m || finish.first < 0 || finish.first >= m){
            flag = false; 
        }

        else if(start.second < 0 || start.second >= n || finish.second < 0 || finish.second >= n){
            flag = false; 
        }
        
        return flag; 
    }//func
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result; 
        bool moved_more_than_one_square = true; 
        int count = 0; 
        m = matrix.size(); 
        n = matrix[0].size(); 
        while(moved_more_than_one_square){
            //direction 1 
            {
                std::pair<int, int> start = {count, count};
                std::pair<int, int> end = {count, n-1-count};  
                if(validRange(start, end) == false){
                    moved_more_than_one_square = false; 
                    break; 
                }
                
                moved_more_than_one_square = false; 
                while(start.second <= end.second){
                    moved_more_than_one_square = true; 
                    result.push_back(matrix[start.first][start.second]); 
                    start.second += 1; 
                }

                if(not moved_more_than_one_square){
                    break; 
                }
            }
            
            {
                std::pair<int, int> start = {1 + count, n-1-count}; 
                std::pair<int, int> end = {m-1-count, n-1-count}; 
                if(validRange(start, end) == false){
                    moved_more_than_one_square = false; 
                    break; 
                }

                moved_more_than_one_square = false; 

                while(start.first <= end.first){
                    moved_more_than_one_square = true; 
                    result.push_back(matrix[start.first][start.second]); 
                    start.first += 1; 
                }

                if(not moved_more_than_one_square){
                    break; 
                }


            }//second direction 

            {
                std::pair<int, int> start = {m-1-count, n-1-1-count}; 
                std::pair<int, int> end = {m-1, 0+count}; 

                if(validRange(start, end) == false){
                    moved_more_than_one_square = false; 
                    break; 
                }

                
                moved_more_than_one_square = false; 
                while(start.second >= end.second){
                    moved_more_than_one_square = true; 
                    result.push_back(matrix[start.first][start.second]);
                    start.second -= 1; 
                }

                if(not moved_more_than_one_square){
                    break; 
                }

            }//third direction

            {
                std::pair<int,int> start = {m-1-1-count, 0+count}; 
                std::pair<int,int> end = {1+count , 0+count}; 
                if(validRange(start, end) == false){
                    moved_more_than_one_square = false; 
                    break; 
                }
                
                moved_more_than_one_square = false; 
                while(start.first >= end.first){
                    moved_more_than_one_square = true; 
                    result.push_back(matrix[start.first][start.second]);
                    start.first -= 1; 
                }

                if(not moved_more_than_one_square){
                    break; 
                }

            }//fourth direction

            ++count; 
        }//while

        return result; 
    }//func
};