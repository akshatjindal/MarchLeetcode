#include <vector>
#include <assert.h> 
using namespace std; 

//this method does O(1) space use. could make it faster at the cost of space. 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit_if_sell_now = 0; 
        int curr_max_profit = 0; 
        int current_lowest_buy = prices[0]; 

        for(int i = 1; i < prices.size(); ++i){
            int current_price = prices[i]; 
            profit_if_sell_now = current_price - current_lowest_buy; 

            if(current_price < current_lowest_buy){
                current_lowest_buy = current_price; 
            }

            if(profit_if_sell_now > curr_max_profit){
                curr_max_profit = profit_if_sell_now; 
            }
        }//the_loop

        if(curr_max_profit < 0){
            return 0; 
        }
        
        return curr_max_profit; 
    }//the func
};


int main(){
    vector<int> temp = {7,1,5,3,6,4};
    vector<int> tempTwo = {7,6,4,3,1}; 
    Solution x; 
    assert(x.maxProfit(temp) == 5);
    assert(x.maxProfit(tempTwo) == 0);
    
}
