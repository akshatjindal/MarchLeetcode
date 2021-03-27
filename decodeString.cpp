//March 27 
//https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3073/

#include <string>
#include <stack>
#include <ctype.h>
using namespace std; 

class Solution {
    int ptr = 0; 
    stack<int> nums; 
public:
    string decodeString(string s) {
        string temp = ""; 
        string decoded = "";
        while(ptr < s.length()){
            if(s[ptr] == ']'){
                for(int i = 0; i < nums.top(); ++i){
                    temp += temp; 
                }
                nums.pop(); 
                ++ptr; 
                return temp; 
            }//base case

            //todo: this should be while isdigit and the inside of the {} should chaange cuz 
            //it could be upto 300 not only from 0-10. 
            if(isdigit(s[ptr]) == true){
                nums.push(s[ptr]); 
                ptr += 2; //cuz the next digit will be a '['
                temp.clear(); 
                decoded = decoded + decodeString(s); //recursive call 
            }
            else{
                temp += s[ptr]; 
            }//else if its a character
        
    }//while
    
    return decoded; 
}
};