#include<iostream>
#include<vector>
#include <algorithm>  // for std::sort
#include <cassert>    // for assert

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0;
        for (int i=0; i<nums.size();){
            if(nums[i] == val){
                nums.erase(nums.begin()+i);
            }
            else{
                i++;
            }
        }
        return nums.size();
        
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {3, 2, 2, 3};       // Input array
    int val = 3;                                // Value to remove
    std::vector<int> expectedNums = {2, 2};    // Expected answer (sorted, no val)

    int k = sol.removeElement(nums, val);      // Call your implementation

    // Assert returned length matches expected length
    assert(k == (int)expectedNums.size());

    // Sort the first k elements of nums
    std::sort(nums.begin(), nums.begin() + k);

    // Assert all elements equal expectedNums
    for (int i = 0; i < k; i++) {
        assert(nums[i] == expectedNums[i]);
    }

    std::cout << "Test passed! New length = " << k << std::endl;
    std::cout << "Array after removal and sorting: ";
    for (int i = 0; i < k; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}