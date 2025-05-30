#include<iostream>
#include<vector>
#include <climits> 

class Solution {
public:
	int maxProfit(std::vector<int>& prices){
		int minPrice = INT_MAX;
		int maxProfit = 0;

		for (int price : prices) {
			if (price < minPrice){
				minPrice = price;
			} else {
				maxProfit = std::max(maxProfit, price - minPrice);
			}
		}
		return maxProfit;
	}
};

int main() {
    Solution solution;

    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    std::vector<int> prices2 = {7, 6, 4, 3, 1};

    std::cout << "Test case 1: ";
    for (int price : prices1) std::cout << price << " ";
    std::cout << "\nMax Profit: " << solution.maxProfit(prices1) << std::endl;

    std::cout << "Test case 2: ";
    for (int price : prices2) std::cout << price << " ";
    std::cout << "\nMax Profit: " << solution.maxProfit(prices2) << std::endl;

    return 0;
}