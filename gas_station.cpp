#include<iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
                int total_tank = 0, current_tank = 0, start_index = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int diff = gas[i] - cost[i];
            total_tank += diff;
            current_tank += diff;

            if (current_tank < 0) {
                // Reset starting point and current tank
                start_index = i + 1;
                current_tank = 0;
            }
        }

        return total_tank >= 0 ? start_index : -1;
    }
};

int main() {
    Solution solution;

    std::vector<int> gas1 = {1, 2, 3, 4, 5};
    std::vector<int> cost1 = {3, 4, 5, 1, 2};
    std::cout << "Test Case 1 Output: " << solution.canCompleteCircuit(gas1, cost1) << std::endl;  // Expected: 3

    std::vector<int> gas2 = {2, 3, 4};
    std::vector<int> cost2 = {3, 4, 3};
    std::cout << "Test Case 2 Output: " << solution.canCompleteCircuit(gas2, cost2) << std::endl;  // Expected: -1

    return 0;
}