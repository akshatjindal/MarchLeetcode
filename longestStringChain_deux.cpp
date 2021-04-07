//April 2 Anki 

#include <vector> 
#include <string> 
#include <cassert> 

using namespace std; 

class Solution {
public:
    
    bool isPredecessor(string first, string second){
        assert(second.length() - 1 == first.length()); 

        bool flag = true; 

        int firstIter = 0; 
        int secondIter = 0; 

        while(firstIter < first.length() && secondIter < second.length()){
            if(first[firstIter] == second[secondIter]){
                ++firstIter; 
            }
            ++secondIter; 

            if(secondIter - firstIter >= 2){
                flag = false; 
                break; 
            }
        }//while
        return flag; 
    }

    int longestStrChain(vector<string>& words) {
        vector<vector<pair<string,int>>> wordToChainLengthStartingAtWord(16); 
        int globalMaxChain = 1; 
        
        //each word is mapped to 1 initially as each word has a chain length of == 1 (itself)
        for(int i = 0; i < words.size(); ++ i){
            int word_length = words[i].length(); 
            std::pair<string, int> temp = {words[i], 1}; 
            wordToChainLengthStartingAtWord[word_length - 1].push_back(temp); 
        }

        for(int i = 16 - 2; i >= 0; --i){
            for(auto & firstPair : wordToChainLengthStartingAtWord[i]){
                int maxChainSeenYetForThisWord = 1; 
                for(auto & secondPair: wordToChainLengthStartingAtWord[i+1]){
                    if(isPredecessor(firstPair.first, secondPair.first) == true){
                        maxChainSeenYetForThisWord = max(maxChainSeenYetForThisWord, secondPair.second + 1); 
                    }
                }//innermost

                firstPair.second = maxChainSeenYetForThisWord; 
                globalMaxChain = max(globalMaxChain, maxChainSeenYetForThisWord); 
            }//inner
        }//outermost

    return globalMaxChain;     
    }//func
};