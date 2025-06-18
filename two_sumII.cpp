#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};  // 1-indexed
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};  
    }
};

int main() {
    Solution sol;

    // Test case
    std::vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = sol.twoSum(numbers, target);

    if (!result.empty()) {
        std::cout << "Indices (0-based): [" << result[0] << ", " << result[1] << "]" << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}