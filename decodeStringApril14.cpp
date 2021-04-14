//Anki April 14
#include <string> 
using namespace std; 

class Solution {
    int ptr = 0; 
    string x; 
    int len = -1; 
public:
    string decodeString(string s) {
        x = s; 
        len = s.length(); 
        return decodeStringHelper(); 
    }

    string decodeStringHelper(){
        string temp; 
        while(ptr < len && x[ptr]!=']'){
            if(isalpha(x[ptr])){
                temp += x[ptr]; 
                ++ptr; 
            }//if its an alphabet

            else if(isdigit(x[ptr])){
                int k = 0; 
                //build the digit first. 

                while(isdigit(x[ptr])){
                    k = (k*10) + x[ptr] - '0'; 
                    ++ptr;
                }

                ++ptr; //skip the opening bracket. 
                string decodedString = decodeStringHelper();
                ++ptr; //skip over the closing bracket. 
                while(k-->0){
                    temp += decodedString; 
                }
            }//if its a digit
        }

        return temp; 
    }
};