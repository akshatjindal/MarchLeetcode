//march 27
#include <vector>
#include <string> 

//giving credit to the following person/solution on leetcode: 
//https://leetcode.com/problems/longest-string-chain/discuss/638101/C%2B%2B-DP-solution-or-Got-96-time-100-memory

using namespace std; 

class Solution {
    bool isPredecessor(string& first, string& second)const {
        int firstPtr = 0; 
        int secondPtr = 0; 
        int diff = 0; 
        while(firstPtr < first.length() && secondPtr < second.length()){
            if(first[firstPtr] == second[secondPtr]){
                ++firstPtr;
            }
            
            ++secondPtr; 
            diff = secondPtr - firstPtr; 
            if(diff >= 2){
                return false; 
            }
        }//while loop

        return true; 
    }//ispredecessor func
    int globalMax = 1; 
public:
    int longestStrChain(vector<string>& words){

        vector<vector<pair<string, int>>> MaxChainStartingAtWord(16); 
        
        for(int i = 0; i < words.size(); ++i){
            MaxChainStartingAtWord[words[i].length() - 1].push_back(std::make_pair(words[i],1));
        } 

        for(int i = 16 - 2; i >= 0; --i){
            for(auto& pairOne: MaxChainStartingAtWord[i]){
                int highestChainLengthForThisWord = 1; 
                for(auto& pairTwo: MaxChainStartingAtWord[i+1]){
                    if(isPredecessor(pairOne.first, pairTwo.first) == true){
                        highestChainLengthForThisWord = 
                            max(highestChainLengthForThisWord, pairTwo.second + 1); 
                        pairOne.second = highestChainLengthForThisWord; 
                        globalMax = max(highestChainLengthForThisWord, globalMax); 
                    }
                }//innermost
            }//inner
        }//outermost 

        return globalMax; 
    }//func
};

//Akshat Jindal

