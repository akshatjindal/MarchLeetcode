//March 25
#include <unordered_map> 
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int max_seen_yet = 0; 
        unordered_map<string, int> wordToMaxChainTillWord; 

        auto comp = [](string a, string b){
            return a.size() < b.size();
        };

        std::sort(words.begin(), words.end(), comp); 

        for(int i = 0; i < words.size(); ++i){
            bool wordExistsAlreadyInMap = false; 
            if(wordToMaxChainTillWord.find(words[i]) != wordToMaxChainTillWord.end()){
                wordExistsAlreadyInMap = true; 
                continue; 
            }

            else if(wordExistsAlreadyInMap == false){
                int longestChainForThisWordsPredecessors = 0; 

                for(int k = 0; k < words[i].length(); ++k){
                    //let k be the charac to be removed
                    string temp = words[i]; 
                    temp.erase(k,1); 
                    auto iter = wordToMaxChainTillWord.find(temp); 
                    if(iter != wordToMaxChainTillWord.end()){
                        if(iter->second > longestChainForThisWordsPredecessors){
                            longestChainForThisWordsPredecessors = iter->second; 
                        }
                    }
                }//inner

                wordToMaxChainTillWord.insert(std::make_pair(words[i],longestChainForThisWordsPredecessors + 1));
                if((longestChainForThisWordsPredecessors + 1) > max_seen_yet){
                    max_seen_yet = longestChainForThisWordsPredecessors + 1; 
                }
            }//elseif
            
        }//outer

        return max_seen_yet; 
    }//func
};


int main(){
    vector<string> kosi = {"a","b","ba","bca","bda","bdca"}; 
    Solution x ; 
    x.longestStrChain(kosi); 
}
