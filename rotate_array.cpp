#include<iostream>
#include<vector>
#include <algorithm>  // for std::sort
#include <cassert>    // for assert

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        std::vector<int> temp (n);
        for (int i=0; i < n; ++i){
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;

    }
};

void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;
    
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    std::cout << "Original vector: ";
    printVector(nums);
    
    solution.rotate(nums, k);
    
    std::cout << "Rotated vector:  ";
    printVector(nums);

    // Expected output after rotation: [5, 6, 7, 1, 2, 3, 4]
    std::vector<int> expected = {5, 6, 7, 1, 2, 3, 4};
    assert(nums == expected);

    std::cout << "Test passed." << std::endl;
    return 0;
}