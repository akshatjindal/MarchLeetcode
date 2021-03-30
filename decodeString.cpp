//March 27 
//https://leetcode.com/problems/decode-string/

#include <string>
#include <stack>
#include <ctype.h>
using namespace std; 

class Solution {
    int ptr = 0; 
    int count = 0; 
    stack<int> nums; 
    string decoded = ""; 
public:
    string decodeString(string s) {
        string temp = ""; 
        while(ptr <= s.length()-1){
            if(s[ptr] == '['){
                nums.push(count); 
                count++; 
                ptr++;
            }
            //base case:
            else if(s[ptr] == ']'){
                nums.pop(); 
                ptr++;
                if(nums.empty() == true){
                    return temp; 
                }
            }//if closing brack
            else if(isdigit(s[ptr]) == true){

                string tempIntString = ""; 
                while(isdigit(s[ptr]) == true){
                    tempIntString += s[ptr];
                    ptr++; 
                }//while isdigit, cuz the num can be 11 or 300 not only 0 - 9 (single digit)
                int numIterations = stoi(tempIntString); 

                temp += decodeString(s);
                //now temp should contain the stuff from inside the [_]
                
                for(int i = 0; i < numIterations; ++i){
                    temp += temp; 
                }//loop
                
                decoded += temp; 
                temp.clear(); 
            }//if digit
            else{
                temp += s[ptr];
                ptr++;  
            }//else if its a charcater

        }//while

        return decoded; 
}
};