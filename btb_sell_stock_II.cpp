#include<iostream>
#include<vector>
#include <climits> 

class Solution {
public:
    int maxProfit(std::vector<int>& prices){
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i){
            if (prices[i] > prices[i - 1]){
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

int main() {
    Solution sol;

    // Test case 1
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    std::cout << "Max Profit (Test 1): " << sol.maxProfit(prices1) << std::endl; // Expected: 7

    // Test case 2
    std::vector<int> prices2 = {1, 2, 3, 4, 5};
    std::cout << "Max Profit (Test 2): " << sol.maxProfit(prices2) << std::endl; // Expected: 4

    // Test case 3
    std::vector<int> prices3 = {7, 6, 4, 3, 1};
    std::cout << "Max Profit (Test 3): " << sol.maxProfit(prices3) << std::endl; // Expected: 0

    return 0;
}