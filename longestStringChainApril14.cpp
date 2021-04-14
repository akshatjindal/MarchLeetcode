//Anki april 14 
#include <string> 
#include <vector> 
#include <algorithm> //for std::max
#include <cassert> //for std::max


using namespace std; 

class Solution {
    private:
    int globalMax = 1; 
    bool isPredecessor(const string& first, const string& second){
        assert(first.length() + 1 == second.length()); 
        bool flag = true; 
        int firstIter = 0; 
        int secondIter = 0; 
        int diff = 0; 
        while(firstIter < first.length() && secondIter < second.length()){
            if(first[firstIter] == second[secondIter])
                ++firstIter; 
            ++secondIter; 
            diff = std::abs(secondIter - firstIter); 
            if(diff >= 2){
                flag = false; 
                break; 
            }
        }

        return flag; 
    }
public:
    int longestStrChain(vector<string>& words) {
        vector<vector<pair<string,int>>> longestChainStartingAtWordX(16); 
        
        for(int i = 0; i < words.size(); ++i){
            longestChainStartingAtWordX[words[i].length()-1].push_back(std::make_pair(words[i],1)); 
        }

        int k = 16 - 1-1; 
        while(k >= 0){
            for(auto& first_pair: longestChainStartingAtWordX[k]){
                int current_max = 1; 
                for(auto& second_pair: longestChainStartingAtWordX[k+1]){
                    if(isPredecessor(first_pair.first,second_pair.first) == true){
                        current_max = std::max(current_max, second_pair.second + 1); 
                    }
                }//inner
                first_pair.second = current_max; 
                globalMax = std::max(globalMax, current_max); 
            }//outer
            k--; 
        }//while
        return globalMax; 
    }
};