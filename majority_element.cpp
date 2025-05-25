#include<iostream>
#include<vector>
#include <algorithm>  // for std::sort
#include <cassert>    // for assert

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
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

int main() {
    Solution solution;

    std::vector<int> test1 = {3, 2, 3};
    std::vector<int> test2 = {2, 2, 1, 1, 1, 2, 2};
    std::vector<int> test3 = {1, 1, 1, 2, 2};

    std::cout << "Test 1: " << solution.majorityElement(test1) << " (Expected: 3)" << std::endl;
    std::cout << "Test 2: " << solution.majorityElement(test2) << " (Expected: 2)" << std::endl;
    std::cout << "Test 3: " << solution.majorityElement(test3) << " (Expected: 1)" << std::endl;

    // Optional assertions to validate correctness
    assert(solution.majorityElement(test1) == 3);
    assert(solution.majorityElement(test2) == 2);
    assert(solution.majorityElement(test3) == 1);

    std::cout << "All test cases passed!" << std::endl;

    return 0;
}