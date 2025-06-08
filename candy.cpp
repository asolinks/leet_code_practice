#include<iostream>
#include<vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int n = ratings.size();
        std::vector<int> candies(n, 1);  // Step 1: Everyone gets at least one candy

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = 0;
        for (int c : candies) {
            totalCandies += c;
        }

        return totalCandies;
    }
};

int main() {
    Solution solution;

     std::vector<int> ratings1 = {1, 0, 2};
    std::cout << "Minimum candies (Example 1): " << solution.candy(ratings1) << std::endl; // Expected: 5

    std::vector<int> ratings2 = {1, 2, 2};
    std::cout << "Minimum candies (Example 2): " << solution.candy(ratings2) << std::endl; // Expected: 4

    std::vector<int> ratings3 = {1, 3, 4, 5, 2};
    std::cout << "Minimum candies (Custom): " << solution.candy(ratings3) << std::endl; // Expected: 11

    return 0;
}