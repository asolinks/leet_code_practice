#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> window;

        for (int i = 0; i < nums.size(); ++i){
            if (window.count(nums[i])) return true;
            window.insert(nums[i]);

            if (window.size() > k){
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    cout << "Test Case 1: " << (solution.containsNearbyDuplicate(nums1, k1) ? "true" : "false") << endl;

    vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;
    cout << "Test Case 2: " << (solution.containsNearbyDuplicate(nums2, k2) ? "true" : "false") << endl;

    vector<int> nums3 = {1, 2, 3, 4, 5};
    int k3 = 2;
    cout << "Test Case 3: " << (solution.containsNearbyDuplicate(nums3, k3) ? "true" : "false") << endl;

    return 0;
}