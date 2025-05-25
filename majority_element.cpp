#include<iostream>
#include<vector>
#include <algorithm>  // for std::sort
#include <cassert>    // for assert

class Solution {
public:
    int majorityElement(std:.vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for(int i=0; i < nums.size(); ++i){
            if(count == 0){
                candidate = nums[i];
            }
            if (candidate == nums[i]){
                ++count;
            }
            else {
                --count;
            }
        }
        return candidate;
        
    }
};