#include<iostream>
#include<vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
    	int farthest = 0;
    	for(int = i; i < nums.size(); ++i){
    		if (i >) return false;
    		farthest = std::max(farthest, i +nums[i]);
    	}
    	return true;
        
    }
};