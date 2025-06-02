#include<iostream>
#include<vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
    	int farthest = 0;
    	for(int i = 0; i < nums.size(); ++i){
    		if (i > farthest) return false;
    		farthest = std::max(farthest, i + nums[i]);
    	}
    	return true;
        
    }
};

int main() {
    // Example input
    std::vector<int> nums = {2, 3, 1, 1, 4}; // Change this for other test cases

    Solution solution;
    bool result = solution.canJump(nums);

    // Print the result
    if (result) {
        std::cout << "Can jump to the end!" << std::endl;
    } else {
        std::cout << "Cannot jump to the end." << std::endl;
    }

    return 0;
}