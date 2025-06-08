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
