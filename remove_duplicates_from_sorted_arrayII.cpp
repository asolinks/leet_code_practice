#include<iostream>
#include<vector>
#include <algorithm>  // for std::sort
#include <cassert>    // for assert

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();

        int k = 2;
        for(int i=2; i < nums.size(); ++i){
            if(nums[i] != nums[k - 2]){
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
        
    }
};

int main() {
    Solution solution;
    
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};

    int newLength = solution.removeDuplicates(nums);

    std::cout << "New length: " << newLength << std::endl;
    std::cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}