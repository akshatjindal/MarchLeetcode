#include <string>
#include <cassert>
using namespace std; 


class Solution {
    private: 
    int ptr = 0; 
    string x; 
public:
    string decodeString(string s) {
        this->x = s; 
        return decodeStringHelper();
    }
    
    string decodeStringHelper(){
        string temp; 
        while(ptr < x.length() && x[ptr]!= ']'){
            if(isalpha(x[ptr])){
                temp += x[ptr++]; 
            }
            else if(isdigit(x[ptr])){
                int k = 0; 
                while(isdigit(x[ptr])){
                    k = (k*10) + x[ptr++] - '0'; 
                }//while its a digit 

                assert(x[ptr] == '[');
                ++ptr; //skip over opening brack 

                string decodedString = decodeStringHelper(); 
                
                ++ptr; //skipping over closing brack or the very last character in string is alpha. 
                while(k-- > 0){
                    temp += decodedString; 
                }


            }//if its a digit
        }//loop
        
        return temp; 
    }//func
    
};//solution