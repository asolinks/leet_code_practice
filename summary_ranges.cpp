#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> output;
        if (nums.empty()) return output;
        
        int left = 0;
        
        for (int i = 1; i <= nums.size(); ++i) {
           
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                if (i - 1 == left) {
                    
                    output.push_back(std::to_string(nums[left]));
                } else {
                    
                    output.push_back(std::to_string(nums[left]) + "->" + std::to_string(nums[i - 1]));
                }
                left = i; 
            }
        }
        
        return output;
    }
};



int main() {
    Solution solution;
    std::vector<int> nums = {0, 1, 2, 4, 5, 7};

    std::vector<std::string> result = solution.summaryRanges(nums);

    std::cout << "Summary Ranges:\n";
    for (const std::string& range : result) {
        std::cout << range << "\n";
    }

    return 0;
}exit
