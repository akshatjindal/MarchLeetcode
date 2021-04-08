//Anki April 8 
#include <string> 
#include <cassert>

using namespace std;

class Solution{
    private:
        string x; 
        int ptr = 0; 
        int len; 
    public: 
        string decodeString(string s){
            this->x = s; 
            this->len = s.length(); 
            return decodeStringHelper(); 
        }

        string decodeStringHelper(){
            string temp; 
            while(ptr < len && x[ptr] != ']'){
               if(isalpha(x[ptr])){
                   temp += x[ptr++]; 
               }//if alphabet
               else if(isdigit(x[ptr])){
                int k = 0; 
                while(isdigit(x[ptr])){
                    k = (k*10) + x[ptr] - '0'; 
                   ++ptr; 
                }//while its a digit

                assert(x[ptr] == '[');
                ++ptr; 
                string decodedString = decodeStringHelper(); 
                assert(ptr == len || x[ptr] == ']'); 
                ++ptr; 

                while(k-- > 0){
                    temp += decodedString; 
                }

               }//if digit
            }//while

            return temp;
        }//func
};