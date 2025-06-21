#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
    	int left = 0, sum = 0, out_put = INT_MAX;

    	for (int right = 0; right < nums.size(); ++right){
    		sum += nums[right];

    		while(sum >= target){
    			out_put = std::min(out_put, right - left + 1);
    			sum -= nums[left];
    			++left;
    		}
    	}
        return out_put == INT_MAX ? 0 : out_put;
    }
};

int main() {
    Solution sol;

    int target = 7;
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};

    int result = sol.minSubArrayLen(target, nums);

    std::cout << "Minimum subarray length with sum ≥ " << target << " is: " << result << std::endl;

    return 0;
}