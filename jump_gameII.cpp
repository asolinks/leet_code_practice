#include<iostream>
#include<vector>

cclass Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        // We do not need to check the last element
        for (int i = 0; i < n - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);
            
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        
        return jumps;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {2, 3, 1, 1, 4}; // Example input

    int result = sol.jump(nums);
    std::cout << "Minimum number of jumps: " << result << std::endl;

    return 0;
}