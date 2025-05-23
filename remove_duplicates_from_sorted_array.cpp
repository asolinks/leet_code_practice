#include<iostream>
#include<vector>
#include <algorithm>  // for std::sort
#include <cassert>    // for assert

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int k = 0;
        for(int i=1; i < nums.size();i++){
            if(nums[i] != nums[k]){
                ++k;
                nums[k]=nums[i];
            }
            
        }
        return k+1;
        
    }
};

int main() {
    std::vector<int> nums = {1, 1, 1, 1, 2, 2, 2};

    Solution sol;
    int newLength = sol.removeDuplicates(nums);

    std::cout << "New length: " << newLength << std::endl;
    std::cout << "Modified array (first " << newLength << " elements): ";
    for (int i = 0; i < newLength; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
