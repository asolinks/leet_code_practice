#include<iostream>
#include<vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max)
                    left_max = height[left];
                else
                    water += left_max - height[left];
                left++;
            } else {
                if (height[right] >= right_max)
                    right_max = height[right];
                else
                    water += right_max - height[right];
                right--;
            }
        }

        return water;
    }
};

int main() {
    Solution solution;
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int trappedWater = solution.trap(height);
    std::cout << "Trapped water: " << trappedWater << std::endl;

    return 0;
}