#include<iostream>
#include<vector>
#include <algorithm>  // for std::sort
#include <cassert>    // for assert

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        std::vector<int> temp (n);
        for (int i=0; i < n; ++i){
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;

    }
};