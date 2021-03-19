//  Created by Akshat Jindal on 3/19/21.
//  Copyright © 2021 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
	
public:
	int findKthLargest(vector<int>& nums, int k) {
        auto greater = [](int i, int j){
            return i > j;
            };
		sort(nums.begin(), nums.end(), greater);
		
		int counter = 1;
		auto iter = nums.begin();
		while(counter != k){
			++iter;
			++counter;
		}
		return *iter;
	}//func
};


int main(){
	vector<int> temp = {3,2,3,1,2,4,5,5,6};
	vector<int> tempTwo = {3,2,1,5,6,4};
	
	Solution x;
	assert(x.findKthLargest(temp, 4) == 4);
	assert(x.findKthLargest(tempTwo, 2) == 5);
	
}
