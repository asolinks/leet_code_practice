#include<iostream>
#include<vector>
#include <algorithm>  // for std::sort
#include <cassert>    // for assert

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for(int i = 0; i < n; ++i){
        	nums1[m+i] = nums2[i];        	
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    // Example input
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // Size is m + n
    int m = 3; // Number of actual elements in nums1
    std::vector<int> nums2 = {2, 5, 6};
    int n = 3; // Number of elements in nums2

    Solution solution;
    solution.merge(nums1, m, nums2, n);

    // Output the result
    std::cout << "Merged array: ";
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}