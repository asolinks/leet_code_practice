#include<iostream>
#include<vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longest = std::max(longest, currentStreak);
            }
        }

        return longest;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};

    int result = solution.longestConsecutive(nums);
    std::cout << "The length of the longest consecutive sequence is: " << result << std::endl;

    return 0;
}