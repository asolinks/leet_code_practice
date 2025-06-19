#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int h = std::min(height[left], height[right]);
            int w = right - left;
            maxArea = std::max(maxArea, h * w);

            if (height[left] < height[right])
                ++left;
            else
                --right;
        }

        return maxArea;
    }
};

int main() {
    Solution solution;

    // Example test case
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = solution.maxArea(height);

    std::cout << "Maximum water container area: " << result << std::endl;

    return 0;
}