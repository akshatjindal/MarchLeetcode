#include <string>
using namespace std; 

class Solution {
    string x; 
    int len; 
public:
    string decodeString(string s) {
        x = s; 
        len = x.length(); 
        return decodeStringHelper(0); 
    }
    
    string decodeStringHelper(int index){
        string temp; 
        while(index <= len-1 && x[index] != '['){
            if(isalpha(x[index])){
                temp += x[index]; 
            }//if its an alphabet
            else if(x[index] == ']'){
                ++index; 
                return decodeStringHelper(index);
            }//if its a closing brack
            else if(isdigit(x[index]) == true){
                int k = x[index++];
                while(isdigit(x[index])){
                    k = (k*10) + x[index]; 
                    ++index; 
                } //while its a digit

                ++index; //this will skip the opening brack
                string decodedString = decodeStringHelper(index); 
                
                while(k > 0){
                    decodedString += decodedString; 
                    k--; 
                }

                temp += decodedString; 
                ++index; 
            }//else if its a digit
        }//while

        return temp; 
    }//func
};