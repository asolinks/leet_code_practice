#include<iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, 1);

        // Calculate prefix products
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Multiply with suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};

int main() {
    // Example input
    std::vector<int> nums = {1, 2, 3, 4};

    // Create an instance of Solution
    Solution solution;

    // Get the result
    std::vector<int> result = solution.productExceptSelf(nums);

    // Print the result
    std::cout << "Output: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}